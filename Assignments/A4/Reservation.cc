#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#include "Reservation.h"

Reservation::Reservation(Guest* g, Room* r, Date* d, int days) : guest(g), room(r), date(d), numDays(days){
  charge = room->getRate() * days;
}

Reservation::~Reservation(){
  delete this->date;
}

int Reservation::getNumDays()  const { return numDays; }
Guest* Reservation::getGuest()       { return guest;   }
Room* Reservation::getRoom()         { return room;    }
float Reservation::getCharge() const { return charge;  }
Date* Reservation::getDate()         { return date;    }

void Reservation::print() const {
  cout << "-- Guest: " << setfill(' ') << setw(9) << guest->getName() << "; ";
  cout << "Room: " << room->getRoomNum();
  cout << " arrival: ";
  date->print();
  cout << "; stay: " <<setfill(' ') << setw(2) << numDays << "; total: $" << setfill(' ') << setw(7) << fixed << setprecision(2) << charge << endl;
}

bool Reservation::lessThan(Reservation* r){
  return date->lessThan(*(r->getDate()));
}
