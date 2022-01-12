/*
  The purpose of this class is to implement all of the initializations of the
  Shelter, as well as utilize the view class to properly output the menu.
*/

#ifndef CONTROL_H
#define CONTROL_H
#include "Shelter.h"
#include "MatchListByScore.h"
#include "MatchListByClient.h"
#include "View.h"


class Control
{
  public:
    Control();
    ~Control();
    void launch();

  private:
    void initShelter();
    void initAnimals();
    void initClients();
    Shelter* shelter;
    View view;

};

#endif
