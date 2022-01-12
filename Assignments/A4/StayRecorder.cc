#include <iostream>
#include <iomanip>
using namespace std;
#include "StayRecorder.h"
#include <sstream>

StayRecorder::StayRecorder(string n) : Recorder(n){}

void StayRecorder::update(Reservation* r){
  if (r->getNumDays() > 3){
    string name = r->getGuest()->getName();
    format(name, r->getNumDays());
    records.push_back(name);
  }
}


void StayRecorder::format(string& s, int d) {
  stringstream ss;

  ss << "Guest" << setfill(' ') << setw(9) << s << "," << setw(4) << d << " nights.\n";

  s = ss.str();
}
