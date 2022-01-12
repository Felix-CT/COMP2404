/*
  The purpose of this class is to act as a collection class for the Room class.
*/
#ifndef ROOMARRAY_H
#define ROOMARRAY_H

#include "defs.h"
#include "Room.h"


class RoomArray
{
  public:
    RoomArray();
    void  add(Room*);
    int   getSize() const;
    Room* get(int);
    void  print() const;

  private:
    Room* elements[MAX_ARR];
    int   size;
};

#endif
