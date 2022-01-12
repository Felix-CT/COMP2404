/*
  The purpose of this class is to emulate a telephone company, which keeps
  track of all of its subscribers, as well as all of the calls directed to or
  made by a subscriber. It can additionally compute who was most frequently
  and who has made the most calls.
*/

#ifndef TELCO_H
#define TELCO_H

#define MAX_NUM_SUBS  64

#include "Subscriber.h"
#include "string.h"
#include "Array.h"


class Telco
{
  public:
    Telco(string);
    ~Telco();
    //double check to see what the return values should be
    void addSub(Subscriber*);
    bool addCall(string, string, int, int, int, int, int, int);
    void computeFreqCaller(string);
    void computeFreqCalled(string);
    void print();

  private:
    string name;
    int numSubs;

    Array* allCalls;
    Subscriber** subs;

    //helper methods
    void printFreqCallers(string[], int, string);
    void printFreqCallersAll(string[], int);
    void printFreqCalled(string[], int, string);
    void printFreqCalledAll(string[], int);

};

#endif
