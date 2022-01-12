/*
  The purpose of this class is to create a report which details how the percentages of animals changed across canada between the years 2011 and 2016. This class will print out the report to the console, as well as save it to a text file.
*/
#ifndef PERCENTAGECHANGEREPORT_H
#define PERCENTAGECHANGEREPORT_H
#include "ReportGenerator.h"
#include "ReportData.h"
#include "CompareBehaviour.h"
using namespace std;


class PercentageChangeReport : public ReportGenerator
{

  public:
    PercentageChangeReport();
    ~PercentageChangeReport();
    void compute();

  private:
    ReportData<float>* rData;
    void populateMaps(Map<string>&, Map<string>&, int, int);
    void calcTotals(Map<string>&, Map<string>&, int&, int&);
    void calculateNums(float&, float&, Map<string>&, Map<string>&, int, int, int, int, vector<string>&);
    void formatData(Map<string>&, Map<string>&, int, int);
    void printReport();
    void printHeader();

};

#endif
