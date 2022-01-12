#include <iostream>
using namespace std;
#include <string>
#include "Control.h"
#include <vector>

Control::Control(){
  FarmDistributionReport* f = new FarmDistributionReport();
  reports.push_back(f);
  PercentageChangeReport* p = new PercentageChangeReport();
  reports.push_back(p);
  HorseReport* h = new HorseReport();
  reports.push_back(h);
  view = View();
}

Control::~Control(){
  for (int i = 0; i < reports.size(); ++i){
    delete reports[i];
  }
}

void Control::launch(){
  ReportGenerator::loadData();

  bool run = true;
  int response;
  while (run){
    view.showMenu(response);
    switch (response){
      case 1:
        reports.at(0)->compute();
        break;
      case 2:
        reports.at(1)->compute();
        break;
      case 3:
        reports.at(2)->compute();
        break;
      case 0:
        run = false;
        ReportGenerator::cleanUp();
        break;
      default:
        cout << "You have not entered a valid selection, please try again.";
        break;
    }
  }
}
