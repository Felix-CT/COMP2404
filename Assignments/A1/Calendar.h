#ifndef CALENDAR_H
#define CALENDAR_H
#include "Date.h"

#define MAX_DATES 64



class Calendar
{
  public:

    Calendar(string);
    ~Calendar();
    string getName();
    void print();
    bool addDate(Date* d);
    void merge(Calendar* c);

  private:
    string name;
    Date** dates;
    int numDates;
    void printDates();
};

#endif
