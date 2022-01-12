/*
  The purpose of this class is to create a report which shows details of the distribution of animals in farms across canada. This also prints the report to the screen, as well as to a text file.
  */
#ifndef FARMDISTRIBUTIONREPORT_H
#define FARMDISTRIBUTIONREPORT_H
#include "ReportGenerator.h"
#include "ReportData.h"
#include "CompareBehaviour.h"
using namespace std;


class FarmDistributionReport : public ReportGenerator
{

  public:
    FarmDistributionReport();
    ~FarmDistributionReport();
    void compute();

  private:
    ReportData<float>* rData;
    void formatData(string, vector<int>&, vector<int>&, int, string&, float&);
    void printReport();
    void calcFarmNums(vector<string>&, vector<string>&, vector<int>&, int, bool&);
    void calcTotals(vector<int>&, vector<string>&, vector<string>&, int&);
    void printHeader();

};

#endif
