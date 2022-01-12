#include <iostream>
using namespace std;
#include <string>
#include "Hotel.h"


Hotel::Hotel(string name, ResManager* manager) : name(name), manager(manager), numGuests(0) {
  guests = new Guest* [MAX_ARR];
  rooms = RoomArray();
}

Hotel::~Hotel(){
  for (int i = 0; i < numGuests; i++){
    delete guests[i];
  }
  delete [] guests;
  for (int i = 0; i < rooms.getSize(); i++){
    delete rooms.get(i);
  }
}

RoomArray Hotel::getRooms() { return rooms; }

void Hotel::addGuest(Guest* g){
  if (numGuests < MAX_ARR){
    guests[numGuests++] = g;
  }else {
    cout <<"max number of guests reached";
  }
}

void Hotel::addRoom(Room* r){
  return rooms.add(r);
}

void Hotel::findGuest(string n, Guest**g){
  for (int i = 0; i < numGuests; i++){
    if (guests[i]->getName() == n){
      *g = guests[i];
    }
  }
}


void Hotel::printGuests() const {
  for (int i = 0; i < numGuests; i++){
    guests[i]->print();
  }
}

void Hotel::printRooms() const {
  cout << "\n\nROOMS:\n";
  rooms.print();
}
