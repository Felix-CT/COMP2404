/*
  The purpose of this class is to record information about a Reservation,
  specifically how long a user is staying in t he hotel.
*/
#ifndef STAYRECORDER_H
#define STAYRECORDER_H
#include "Recorder.h"


class StayRecorder : public Recorder
{
  public:
    StayRecorder(string);
    virtual void update(Reservation*);

  private:
    void format(string&, int);

};

#endif
