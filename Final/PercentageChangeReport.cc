#include <iostream>
#include <iomanip>
using namespace std;
#include <string>
#include <fstream>
#include <iomanip>
#include "PercentageChangeReport.h"

PercentageChangeReport::PercentageChangeReport() : rData(new ReportData<float>(new AscBehaviour<float>)){}

PercentageChangeReport::~PercentageChangeReport()
{
    delete rData;
}

void PercentageChangeReport::compute(){
  Map<string> animals1;
  Map<string> animals2;
  int totalAnimals1 = 0;
  int totalAnimals2 = 0;
  int year1 = 2011;
  int year2 = 2016;

  populateMaps(animals1, animals2, year1, year2);
  calcTotals(animals1, animals2, totalAnimals1, totalAnimals2);

  formatData(animals1, animals2, totalAnimals1, totalAnimals2);

  printHeader();
  printReport();

  delete rData;
  rData = new ReportData<float>(new AscBehaviour<float>);
}

void PercentageChangeReport::populateMaps(Map<string>& animals1, Map<string>& animals2, int year1, int year2){
  vector<int> keys = yearMap.getKeys();
  for (int i = 0; i < keys.size(); ++i){
      for (int j = 0; j < yearMap[keys[i]].size(); ++j) {
          if (yearMap[keys[i]][j]->getRegion() == "CAN") {
              if (keys[i] == year1) {
                  animals1.add(yearMap[keys[i]][j]->getAnimal(), yearMap[keys[i]][j]);
              }
              else if (keys[i] == year2) {
                  animals2.add(yearMap[keys[i]][j]->getAnimal(), yearMap[keys[i]][j]);
              }
          }
      }
  }
}

void PercentageChangeReport::calcTotals(Map<string>& animals1, Map<string>& animals2, int& totalAnimals1, int& totalAnimals2){
  vector<string> keys1 = animals1.getKeys();
  for (int i = 0; i < keys1.size(); ++i){
      for (int j = 0; j < animals1[keys1[i]].size(); ++j) {
          totalAnimals1 += animals1[keys1[i]][j]->getNumAnimals();
      }
  }

  vector<string> keys2 = animals2.getKeys();
  for (int i = 0; i < keys2.size(); ++i){
      for (int j = 0; j < animals2[keys2[i]].size(); ++j) {
          totalAnimals2 += animals2[keys2[i]][j]->getNumAnimals();
      }
  }
}

void PercentageChangeReport::formatData(Map<string>& animals1, Map<string>&animals2, int totalAnimals1, int totalAnimals2){
  stringstream ss;
  vector<string> keys = animals1.getKeys();
  float num1 = 0.0;
  float num2 = 0.0;
  float change = 0.0;

  for (int i = 0; i < keys.size(); ++i){
      for (int j = 0; j < animals1[keys[i]].size(); ++j) {
          try {
              if (totalAnimals1 == 0 || totalAnimals2 == 0)
                  throw "Divided by zero !!!";

              calculateNums(num1, num2, animals1, animals2, totalAnimals1, totalAnimals2, i, j, keys);
          }
          catch (const char* error) {
              num1 = 0.0;
              num2 = 0.0;
          }
          float change = num2 - num1;

          if (change > 0.0) {
              ss << right << setw(20) << keys[i] << setw(10) << fixed << setprecision(1) << num1 << setw(10) << num2 << setw(7) << "+" << change;

          }
          else {
              ss << right << setw(20) << keys[i] << setw(10) << fixed << setprecision(1) << num1 << setw(10) << num2 << setw(10) << change;
          }
          rData->add(change, ss.str());
          ss.str("");
      }
  }
}


void PercentageChangeReport::printReport(){
  cout << *rData;

  ofstream outfile("PercentageChangeReport.txt", ios::out);

  if (!outfile) {
    cout << "Error:  could not open file" << endl;
    exit(1);
  }
  outfile << endl << endl;
  outfile << setfill(' ') << setw(53) << "PERCENTAGE CHANGE OF ANIMALS (2011-2016)\n";
  outfile << setw(53) << "----------------------------------------\n\n";
  outfile << "                          2011      2016     Change\n\n";
  outfile << *rData;
}


void PercentageChangeReport::printHeader() {
    cout << endl << endl;
    cout << setfill(' ') << setw(53) << "PERCENTAGE CHANGE OF ANIMALS (2011-2016)\n";
    cout << setw(53) << "----------------------------------------\n\n";
    cout << "                          2011      2016     Change\n\n";

}


void PercentageChangeReport::calculateNums(float& num1, float& num2, Map<string>& animals1, Map<string>& animals2, int totalAnimals1, int totalAnimals2, int i, int j, vector<string>& keys) {

    if (i != 0 && animals2[keys[i]] == animals2[keys[0]]) {
        num1 = ((float)animals1[keys[i]][j]->getNumAnimals() / (float)totalAnimals1) * 100;
        num2 = 0.0;
    }
    else if (i != 0 && animals1[keys[i]] == animals1[keys[0]]) {
        num1 = 0.0;
        num2 = ((float)animals2[keys[i]][j]->getNumAnimals() / (float)totalAnimals2) * 100;
    }
    else {
        num1 = ((float)animals1[keys[i]][j]->getNumAnimals() / (float)totalAnimals1) * 100;
        num2 = ((float)animals2[keys[i]][j]->getNumAnimals() / (float)totalAnimals2) * 100;
    }
}
