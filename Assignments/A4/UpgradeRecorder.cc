#include <iostream>
#include <iomanip>
using namespace std;
#include "UpgradeRecorder.h"
#include <sstream>

UpgradeRecorder::UpgradeRecorder(string n) : Recorder(n){}

void UpgradeRecorder::update(Reservation* r){
  if (!r->getGuest()->getPremium() && r->getCharge() > 1500){
    string name = r->getGuest()->getName();
    format(name, r->getCharge());
    records.push_back(name);
  }
}

void UpgradeRecorder::format(string& s, int c) {
  stringstream ss;

  ss << "Guest" << setfill(' ') << setw(9) << s << ", " << "$" << c << endl;

  s = ss.str();
}
