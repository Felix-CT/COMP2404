#include <iostream>
#include <iomanip>
using namespace std;
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include "ReportGenerator.h"

Map<int> ReportGenerator::yearMap;
Map<string> ReportGenerator::regionMap;
Map<string> ReportGenerator::animalMap;
vector<Record*> ReportGenerator::records;


void ReportGenerator::loadData(){
  int year, numFarms, numAnimals;
  string region, subRegion, animal;

  ifstream infile("farms.dat", ios::in);

  if (!infile) {
    cout << "Error: could not open file" << endl;
    exit(1);
  }

  //maybe want a try/catch here?

  while ( infile >> year >> region >> subRegion >> animal >> numFarms >> numAnimals ) {
    Record* rec = new Record(year, region, subRegion, animal, numFarms, numAnimals);
    records.push_back(rec);
    regionMap.add(region, rec);
    animalMap.add(animal, rec);
    yearMap.add(year, rec);
  }
}

void ReportGenerator::cleanUp(){
  for (int i = 0; i < records.size(); ++i){
    delete records[i];
  }
}
