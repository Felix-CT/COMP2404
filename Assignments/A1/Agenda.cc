#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Agenda.h"

Agenda::Agenda(string n)
{
  //initializing variables
  name = n;
  numCalendars = 0;
  Calendar* calendars[MAX_CALENDARS];
}

Agenda::~Agenda(){
  //de-allocates the memory of all of the calendars
  for (int i = 0; i < numCalendars; i++){
    delete calendars[i];
  }
}

bool Agenda::add(Calendar* c){
  //adds the calendar to the array of calendars
  if (numCalendars < MAX_CALENDARS){
    calendars[numCalendars] = c;
    ++numCalendars;
    return true;
  }
  return false;
}

bool Agenda::find(string n, Calendar** c){
  //loops through the calendars in the agenda to find the one of name 'n'
  for (int i = 0; i < numCalendars; i ++){
    if (calendars[i]->getName() == n){
      *c = calendars[i];
      return true;
    }
  }
  return false;
}


bool Agenda::add(Date *d, string n){
  //passing in a nullpointer that is assigned the calender of name "n" if it exists
  Calendar* tempCal = nullptr;
  if(find(n, &tempCal)){
    return tempCal->addDate(d);
  }

  //deallocate the memory used for the date object that was unable to be added
  delete d;
  return false;
}

void Agenda::print(){
  //merges both calendars into one, prints the agenda's name, and then prints
  //the combined calendar.
  Calendar* tempCal = new Calendar("Complete Agenda");
  for (int i = 0; i < numCalendars; i++){
    tempCal->merge(calendars[i]);
  }

  cout << "Agenda name: " << name << "\n";
  tempCal->print();

  //de-allocates the memory used by the temp calendar
  delete tempCal;
}
