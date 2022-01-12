/*
  The purpose of this class is to act as a base class for the different reports that will be created throughout the program. it also contains the records that will be used to generate the reports.
*/
#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include "Map.h"
#include "Record.h"


class ReportGenerator
{

  public:
    virtual void compute() {};
    static void loadData();
    static void cleanUp();
    virtual ~ReportGenerator() {}


  protected:
   //static data member that stores the collection of all the records read in from the census data file
   static vector<Record*> records;

   //these maps must be loaded at the same time that we're loading the data from the file
   static Map<int> yearMap;
   static Map<string> regionMap;
   static Map<string> animalMap;

};

#endif
