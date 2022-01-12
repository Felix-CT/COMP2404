#include <iostream>
using namespace std;
#include <string>
#include "Date.h"
#include "Calendar.h"
#include "Agenda.h"

void initDates(Agenda& ag);

int main()
{
  //statically allocating a new agenda
  Agenda a1 = Agenda("newAgenda");

  //dynamically allocating the two calendars
  Calendar* c1 = new Calendar("Work");
  Calendar* c2 = new Calendar("Home");

  //adding the two calendars to the agenda
  a1.add(c1);
  a1.add(c2);

  //adding all of the dates to the calendars in the agenda
  initDates(a1);

  //printing out both calendars
  c1->print();
  c2->print();

  //printing out the agenda
  a1.print();
  return 0;
}


void initDates(Agenda& ag)
{
  ag.add(new Date("2021 National Heroes Conference", 23, 10, 2021, 8, 30, 800), "Work");
  ag.add(new Date("2020 National Heroes Conference", 24, 10, 2020, 8, 30, 800), "Work");
  ag.add(new Date("Slay dragon", 6, 4, 2021, 9, 30, 90), "Work");
  ag.add(new Date("Climb Mount of Dooom", 2, 4, 2021, 10, 0, 360), "Work");
  ag.add(new Date("some thing", 32, 3, 2021, 10, 0, 45), "Work");
  ag.add(new Date("some other thing", 1, 2, 2020, 14, 0, 30), "Other");
  ag.add(new Date("some new thing", 18, 2, 2020, 14, 0, 12), "Test");
  ag.add(new Date("Lunch with Gwendolyn", 29, 3, 2021, 11, 45, 100), "Home");
  ag.add(new Date("Heroes meeting", 8, 1, 2021, 9, 0, 60), "Work");
  ag.add(new Date("Practice sparring", 11, 1, 2021, 13, 45, 80, true, 13), "Work");
  ag.add(new Date("Sharpen sword", 11, 1, 2021, 13, 5, 30, true, 13), "Work");
  ag.add(new Date("Dinner with Harold", 27, 3, 2021, 18, 30, 120), "Home");
  ag.add(new Date("Theatre with Harold", 27, 3, 2021, 16, 0, 100), "Home");
  ag.add(new Date("Grocery shopping", 23, 1, 2021, 9, 45, 90, true, 10), "Home");
  ag.add(new Date("Meeting with Wizard", 25, 3, 2021, 6, 15, 20), "Work");
  ag.add(new Date("some bad thing", 18, 22, 2020, 14, 0, 12), "Home");

}
