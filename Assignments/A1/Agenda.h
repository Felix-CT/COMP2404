#ifndef AGENDA_H
#define AGENDA_H
#include "Calendar.h"

#define MAX_CALENDARS  15

class Agenda
{
  public:

    Agenda(string);
    ~Agenda();
    string getName();
    void print();
    bool add(Calendar* c);
    bool add(Date *d, string n);

  private:
    string name;
    //will need to change the number based on what you want
    Calendar* calendars[MAX_CALENDARS];
    int numCalendars;
    bool find(string n, Calendar** c);
};

#endif
