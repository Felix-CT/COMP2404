/*
  The purpose of this class is to record information about the Reservations,
  specifically how much money each reservation is costing the guest.
*/
#ifndef UPGRADERECORDER_H
#define UPGRADERECORDER_H
#include "Recorder.h"
#include "Reservation.h"


class UpgradeRecorder : public Recorder
{
  public:
    UpgradeRecorder(string);
    virtual void update(Reservation*);

  private:
    void format(string&, int);


};

#endif
