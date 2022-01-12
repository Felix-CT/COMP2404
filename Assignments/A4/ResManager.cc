#include <iostream>
using namespace std;
#include <string>
#include "ResManager.h"


ResManager::ResManager(Hotel* hotel) : hotel(hotel), numReservations(0) {
  reservations = new Reservation* [MAX_ARR];
}

ResManager::~ResManager(){
  for (int i = 0; i < numReservations; i++){
    delete reservations[i];
  }
  delete [] reservations;

  for (int i = 0; i < recorders.size(); i++) {
      delete recorders[i];
  }
}

void ResManager::setHotel(Hotel* h) { hotel = h; }

void ResManager::addReservation(string name, int yr, int mth, int day, int stay, ReqRoomType req){
  Guest* goodGuest = NULL;
  hotel->findGuest(name, &goodGuest);

  if (stay > 31) {
      cout << "Reservation could not be created.\n";
      return;
  }

  Date* newDate = new Date(day, mth, yr);

  Room* goodRoom = NULL;
  for (int i = 0; i < hotel->getRooms().getSize(); i++){
    if (hotel->getRooms().get(i)->getType() == req){
      bool found = true;

      for (int j = 0; j < numReservations; j++){
        if (reservations[j]->getRoom() == hotel->getRooms().get(i)){
            if (checkConflictingDates(newDate, stay, j)) {
                found = false;
                break;
          }
        }
      }
      if (found) {
          goodRoom = hotel->getRooms().get(i);
          break;
      }
    }
  }

  if (!goodRoom){
    cout << "ERROR:  Registration request for " << name << ", " << yr << "-" << mth << "-" << day << ":  No room of matching type available" << endl;
    delete newDate;
    return;
  }


  if (goodGuest){
    Reservation* newRes = new Reservation(goodGuest, goodRoom, newDate, stay);
    addResHelper(newRes);

    int points;
    goodRoom->computePoints(points);
    goodGuest->addPts(points * stay);

    notify(newRes);
  }
  else {
      cout << "ERROR:  Guest "<< name << " does not exist\n";
      delete newDate;
      return;
  }
}

void ResManager::printRecords(){
  for (int i = 0; i < recorders.size(); i++){
    recorders[i]->printRecords();
  }
}

void ResManager::print(){
  for (int i = 0; i < numReservations; i++){
    reservations[i]->print();
  }
}


void ResManager::subscribe(Recorder* r){
  recorders.push_back(r);
}

void ResManager::notify(Reservation* r){
  for (int i = 0; i < recorders.size(); i++){
    recorders[i]->update(r);
  }
}

bool ResManager::checkConflictingDates(Date* newDate, int stay, int j) {
    Date* resDate = reservations[j]->getDate();

    Date tempNewDate(*newDate);
    tempNewDate.add(stay);
    Date tempResDate(*(reservations[j]->getDate()));
    tempResDate.add(reservations[j]->getNumDays());

    if ((!newDate->lessThan(*(reservations[j]->getDate())) &&
        newDate->lessThan(tempResDate)) ||
        (!tempNewDate.lessThan(*(reservations[j]->getDate())) &&
          tempNewDate.lessThan(tempResDate)) ||
          newDate->equals(*(reservations[j]->getDate())) ||
          tempNewDate.equals(tempResDate) ||
        (
          (!newDate->lessThan(*(reservations[j]->getDate())) &&
            newDate->lessThan(tempResDate)) ||
          (!tempNewDate.lessThan(*(reservations[j]->getDate())) &&
            tempNewDate.lessThan(tempResDate))
        )
        ) {
        return true;
    }
    return false;
}

void ResManager::addResHelper(Reservation* newRes)
{
    if (numReservations == 0) {
        reservations[numReservations] = newRes;
    }
    else {
        for (int i = numReservations - 1; i >= 0; i--) {
            if (reservations[i]->lessThan(newRes)) {
                reservations[++i] = newRes;
                break;
            }
            else {
                reservations[i + 1] = reservations[i];
                if (i == 0) {
                    reservations[i] = newRes;
                }
            }
        }
    }
    ++numReservations;
}
