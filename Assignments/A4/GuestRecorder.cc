#include <iostream>
#include <sstream>
using namespace std;
#include "GuestRecorder.h"

GuestRecorder::GuestRecorder(string n) : Recorder(n) {}

void GuestRecorder::update(Reservation* r){
    string message;
    if (r->getRoom()->getType() == C_PREM && !r->getGuest()->getPremium()) {
      message = "premium guest offer for " + r->getGuest()->getName() + "\n";

    }
    records.push_back(message);
}

