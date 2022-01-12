#include <iostream>
#include <iomanip>
using namespace std;
#include <string>
#include <fstream>
#include <iomanip>
#include "HorseReport.h"

HorseReport::HorseReport() : rData(new ReportData<float>(new DescBehaviour<float>)){}

HorseReport::~HorseReport()
{
    delete rData;
}

void HorseReport::compute(){
  Map<string> regions;
  string animal = "Horses-Ponies";
  int year = 2016;

  populateMap(regions, animal, year);

  formatData(regions);

  printHeader();
  printReport();

  delete rData;
  rData = new ReportData<float>(new DescBehaviour<float>);
}


void HorseReport::populateMap(Map<string>& regions, string animal, int year){
  vector<Record*> recs = animalMap[animal];
  Record* highestRec = nullptr;
  string curRegion = "";
  for (int i = 0; i < recs.size(); ++i){
    if (recs[i]->getRegion() != "CAN" && recs[i]->getSubRegion() != "All" && recs[i]->getYear() == year){
      if (curRegion == ""){
        highestRec = recs[i];
        curRegion = highestRec->getRegion();
      }else if (curRegion == recs[i]->getRegion()){
        if (recs[i]->getNumAnimals() > highestRec->getNumAnimals()){
            highestRec = recs[i];
            curRegion = highestRec->getRegion();
        }
      } else{
        regions.add(curRegion, highestRec);
        highestRec = recs[i];
        curRegion = highestRec->getRegion();
      }
    }
    if (recs[i]->getRegion() != "CAN" && recs[i]->getYear() == year && recs[i]->getSubRegion() == "All" &&
       (i == recs.size() - 1 || recs[i]->getRegion() != recs[i+1]->getRegion())){
         Record tempRecord(year, "", "", animal, 0, 0);
         regions.add(recs[i]->getRegion(), &tempRecord);
    }
  }
}



void HorseReport::formatData(Map<string>& records){
  stringstream ss;
  vector<string> keys = records.getKeys();

  for (int i = 0; i < keys.size(); ++i){
    ss << right << setw(20) << keys[i] << setw(30) << records[keys[i]][0]->getSubRegion() << setw(20) << records[keys[i]][0]->getNumAnimals();
    rData->add(records[keys[i]][0]->getNumAnimals(), ss.str());
    ss.str("");
  }
}


void HorseReport::printReport(){
  cout << *rData;

  ofstream outfile("HorseReport.txt", ios::out);

  if (!outfile) {
    cout << "Error:  could not open file" << endl;
    exit(1);
  }
  outfile << endl << endl;
  outfile << setfill(' ') << setw(71) << "SUB-REGION WITH MOST HORSES/PONIES BY REGION IN 2016\n";
  outfile << setw(72) << "----------------------------------------------------\n\n";
  outfile << *rData;
}


void HorseReport::printHeader() {
    cout << endl << endl;
    cout << setfill(' ') << setw(71) << "SUB-REGION WITH MOST HORSES/PONIES BY REGION IN 2016\n";
    cout << setw(72) << "----------------------------------------------------\n\n";

}
