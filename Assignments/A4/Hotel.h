/*
  The purpose of this class is to represent a hotel, which will keep track of
  its guests and rooms, as well as the manager who takes care of the reservations.
*/
#ifndef HOTEL_H
#define HOTEL_H
#include "string.h"
#include "Guest.h"
#include "RoomArray.h"
#include "ResManager.h"

class ResManager;

class Hotel
{
  public:
    Hotel(string, ResManager*);
    ~Hotel();
    RoomArray getRooms();
    void printGuests()     const;
    void printRooms()      const;
    void addGuest(Guest*);
    void addRoom(Room*);
    void findGuest(string, Guest**);

  private:
    string name;
    Guest** guests;
    int numGuests;
    RoomArray rooms;
    ResManager* manager;

};

#endif
