/*
  The purpose of this class is to represent a reservation in a hotel, which can
  be compared to other reservations and also contain various information.
*/
#ifndef RESERVATION_H
#define RESERVATION_H
#include "Guest.h"
#include "Room.h"
#include "Date.h"


class Reservation
{
  public:
    Reservation(Guest*, Room*, Date*, int);
    ~Reservation();
    int getNumDays() const;
    Room* getRoom();
    Guest* getGuest();
    float getCharge() const;
    Date* getDate();
    void print() const;
    bool lessThan(Reservation*);

  private:
    Guest* guest;
    int numDays;
    Room* room;
    float charge;
    Date* date;

};

#endif
