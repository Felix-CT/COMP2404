/*
  The purpose of this class is to record the guests that are staying at the hotel
  that can become premium members.
*/
#ifndef GUESTRECORDER_H
#define GUESTRECORDER_H
#include "Recorder.h"


class GuestRecorder : public Recorder
{
  public:
    GuestRecorder(string);
    virtual void update(Reservation*);

  private:
    void format(string&, int);

};

#endif
