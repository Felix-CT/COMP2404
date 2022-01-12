/*
  The purpose of this class is to represent a room in a hotel, and compute the
  amount of daily points a guest will obtain by staying here.
*/
#ifndef ROOM_H
#define ROOM_H
#include "string.h"
#include "defs.h"

class Room
{
  public:
    Room(ReqRoomType, int, float);
    ReqRoomType getType() const;
    int getRoomNum()      const;
    float getRate()       const;
    void print()          const;
    void computePoints(int&);

  private:
    ReqRoomType type;
    int roomNum;
    float rate;

};

#endif
