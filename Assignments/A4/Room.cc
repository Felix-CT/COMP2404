#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#include "Room.h"


Room::Room(ReqRoomType type, int roomNum, float rate) : type(type),  roomNum(roomNum), rate(rate) {}

ReqRoomType Room::getType() const { return type; }
int Room::getRoomNum()      const { return roomNum; }
float Room::getRate()       const { return rate; }

void Room::print() const{
  cout << "-- " << roomNum;
  cout << "  ";
  if (type == C_REG) {
      cout << left << setfill(' ') << setw(8) << "Regular";
  }
  else if (type == C_PREM) {
      cout << left << setfill(' ') << setw(8) << "Premium";
  }
  else if (type == C_SUITE) {
      cout << left << setfill(' ') << setw(8) << "Suite";
  }
  cout << "room:  $";

  cout << right << setfill(' ') << setw(7) << fixed << setprecision(2) << rate << " per night\n";
}

void Room::computePoints(int& pts){
  if (type == C_REG){
    pts = rate / 10;
  }else if (type == C_PREM){
    pts = rate *(0.15);
  }else if (type == C_SUITE){
    pts = rate / 5;
  }
}
