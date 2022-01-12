#include <iostream>
#include <iomanip>
using namespace std;
#include <string>
#include <fstream>
#include <iomanip>
#include "FarmDistributionReport.h"

FarmDistributionReport::FarmDistributionReport() : rData(new ReportData<float>(new DescBehaviour<float>)){}

FarmDistributionReport::~FarmDistributionReport()
{
    delete rData;
}

void FarmDistributionReport::compute(){
  vector<int> farmTotals;
  vector<string> animals;
  vector<string> regions = regionMap.getKeys();


  int totalNumFarms = 0;


  calcTotals(farmTotals, animals, regions, totalNumFarms);

  for (int i = 1; i < regionMap.getNumKeys(); ++i){
    vector<int> farmNums;
    for (int j = 0; j < animals.size(); ++j) {
      farmNums.push_back(0);
    }
    bool changed = false;
    calcFarmNums(regions, animals, farmNums, i, changed);
    if (changed) {
        string line;
        float percentage;
        formatData(regions[i], farmNums, farmTotals, totalNumFarms, line, percentage);
        rData->add(percentage, line);
    }
  }
  printHeader();
  printReport();

  delete rData;
  rData = new ReportData<float>(new DescBehaviour<float>);
}



void FarmDistributionReport::formatData(string region, vector<int>& farmNums, vector<int>& farmTotals, int totalNumFarms, string& line, float& percentage){
  stringstream ss;
  float regionNumAnimals = 0.0;
  ss << region << setfill(' ') << setw(9);
  for (int i = 0; i < farmNums.size(); ++i){
      float result = 0;

      try {
          if (farmTotals[i] == 0)
              throw "Divided by zero !!!";
          result = ((float) farmNums[i] / (float) farmTotals[i]) * 100;
      }

      catch (const char* error) {
          result = 0.0;
      }
     ss << setw(10) << fixed << setprecision(1) << result;
     regionNumAnimals += farmNums[i];
  }
  percentage = ((float) regionNumAnimals / (float ) totalNumFarms);
  ss << setw(10) << fixed << setprecision(1) << percentage * 100;
  line = ss.str();
}

void FarmDistributionReport::printReport(){
  cout << *rData;

  ofstream outfile("FarmDistributionReport.txt", ios::out);

  if (!outfile) {
    cout << "Error:  could not open file" << endl;
    exit(1);
  }
  outfile << setfill(' ') << setw(70) << "PERCENTAGE OF FARMS BY REGION IN 2016\n";
  outfile << setw(70) << "-------------------------------------\n\n";
  outfile << "       Horses/    Goats    Llamas    Rabbits   Bison/     Elk/     Domestic   Wild      Mink    Totals\n";
  outfile << "       Ponies              Alpacas             Buffalo    Wapiti     Deer     Boars\n";

  outfile << *rData;
}




void FarmDistributionReport::calcFarmNums(vector<string>& regions, vector<string>& animals, vector<int>& farmNums, int i, bool& changed){
  int animalPos = 0;
  for (int j = 0; j < regionMap[regions[i]].size(); ++j){
    if (regionMap[regions[i]][j]->getSubRegion() == "All" && regionMap[regions[i]][j]->getYear() == 2016){
        for (int x = 0; x < animals.size(); x++) {
            if (animals[x] == regionMap[regions[i]][j]->getAnimal()) {
                animalPos = x;
                break;
            }
        }
        farmNums[animalPos] += regionMap[regions[i]][j]->getNumFarms();

      changed = true;
    }
  }
}


void FarmDistributionReport::calcTotals(vector<int>& farmTotals, vector<string>& animals, vector<string>& regions, int& totalNumFarms){
  int animalPos = 0;
  for (int i = 0; i < regionMap.getNumKeys(); ++i){
    for (int j = 0; j < regionMap[regions[i]].size(); ++j){
        if (i == 0 ) {
            if (animals.size() == 0) {
                animals.push_back(regionMap[regions[i]][j]->getAnimal());
                farmTotals.push_back(0);
            }
            else {
                for (int x = 0; x < animals.size(); x++) {
                    if (animals[x] == regionMap[regions[i]][j]->getAnimal()) {
                        break;
                    }
                    if (x == animals.size() - 1) {
                        animals.push_back(regionMap[regions[i]][j]->getAnimal());
                        farmTotals.push_back(0);
                    }
                }
            }
        }

      if (regionMap[regions[i]][j]->getSubRegion() == "All" && regionMap[regions[i]][j]->getYear() == 2016 && regionMap[regions[i]][j]->getRegion() != "CAN"){
        for (int x = 0; x < animals.size(); x++) {
            if (animals[x] == regionMap[regions[i]][j]->getAnimal()) {
                animalPos = x;
                break;
            }
        }
        farmTotals[animalPos] += regionMap[regions[i]][j]->getNumFarms();
        totalNumFarms += regionMap[regions[i]][j]->getNumFarms();
      }
    }
  }
}

void FarmDistributionReport::printHeader(){
  cout << setfill(' ') << setw(70) << "PERCENTAGE OF FARMS BY REGION IN 2016\n";
  cout << setw(70) << "-------------------------------------\n\n";
  cout << "       Horses/    Goats    Llamas    Rabbits   Bison/     Elk/     Domestic   Wild      Mink    Totals\n";
  cout << "       Ponies              Alpacas             Buffalo    Wapiti     Deer     Boars\n";
}
