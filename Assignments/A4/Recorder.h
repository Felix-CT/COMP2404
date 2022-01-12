/*
  The purpose of this class is to provide a base class for the other recorders
  that will record information about reservations.
*/
#ifndef RECORDER_H
#define RECORDER_H
#include "Reservation.h"
#include <string>
#include <vector>


class Recorder
{
  public:
    Recorder(string);
    virtual void printRecords() const;
    virtual void update(Reservation*) = 0;

  protected:
    string name;
    vector<string> records;

};

#endif
