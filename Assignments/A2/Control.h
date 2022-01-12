/*
  The purpose of this class is to be able to help use the program, as it creates
  the objects we need and initializes the data we need as well.
*/

#ifndef CONTROL_H
#define CONTROL_H

#include "Telco.h"
#include "View.h"

class Control
{
  public:
    Control(string);
    ~Control();
    void launch();

  private:
    void initData(Telco*);
    void initSubscribers(Telco*);
    void initCalls(Telco*);

    Telco* telco;
    View* view;
};

#endif
