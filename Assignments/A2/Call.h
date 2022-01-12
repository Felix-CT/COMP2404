/*
  The purpose of this class is to keep track of a call, which has Date and Time
  object pointers in order to keep track of when it occured, and compare it to
  other calls.
*/
#ifndef CALL_H
#define CALL_H
#include "Date.h"
#include "Time.h"

class Call
{
  public:
    Call(string, string, int, int=0, int=0, int=2000, int=0, int=0);
    ~Call();
    void print();
    bool greaterThan(Call*);
    string getSrc();
    string getDest();

  private:
    string src;
    string dest;
    int duration;
    Date* startDate;
    Time* startTime;
};

#endif
