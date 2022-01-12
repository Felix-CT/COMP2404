/*
  The purpose of this class is to implement all of the initializations of the
  Hotel and the reservation manager, as well as of the recorders for the res
  manager. Additionally, it also manages the contorl flow of the menu.
*/
#ifndef CONTROL_H
#define CONTROL_H
#include "ResManager.h"
#include "Hotel.h"
#include "StayRecorder.h"
#include "GuestRecorder.h"
#include "UpgradeRecorder.h"
#include "View.h"

class Control
{
  public:
    Control();
    ~Control();
    void launch();

  private:
    void initHotel();
    ResManager* resMgr;
    Hotel* hotel;
    View view;

};

#endif
