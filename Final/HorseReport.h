/*
  The purpose of this class is to create a report detailing which sub-regions have the highest number of horses. it additionally prints the report to the screen, and saves it to a text file.
*/
#ifndef HORSEREPORT_H
#define HORSEREPORT_H
#include "ReportGenerator.h"
#include "ReportData.h"
#include "CompareBehaviour.h"
using namespace std;


class HorseReport : public ReportGenerator
{

  public:
    HorseReport();
    ~HorseReport();
    void compute();

  private:
    ReportData<float>* rData;
    void populateMap(Map<string>&, string, int);
    void formatData(Map<string>&);
    void printReport();
    void printHeader();

};

#endif
