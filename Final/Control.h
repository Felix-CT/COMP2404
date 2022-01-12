/*
  The purpose of this class is to implement all of the initializations of the
  ReportGenerator objects, as well as utilize the view object in order to display
  the menu.
*/
#ifndef CONTROL_H
#define CONTROL_H
using namespace std;
#include "ReportGenerator.h"
#include "FarmDistributionReport.h"
#include "PercentageChangeReport.h"
#include "HorseReport.h"
#include "View.h"
#include <vector>

class Control
{
  public:
    Control();
    ~Control();
    void launch();

  private:
    vector<ReportGenerator*> reports;
    View view;

};

#endif
