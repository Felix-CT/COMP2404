#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include "Calendar.h"



Calendar::Calendar(string n){
  name = n;
  numDates = 0;
  dates = new Date*[MAX_DATES];
}

Calendar::~Calendar(){
  //deallocating each date in the calcendar
  for (int i = 0; i < numDates; i++){
    delete dates[i];
  }
  //deallocating the memory used for the date array
  delete [] dates;
}

string Calendar::getName(){
  return name;
}

bool Calendar::addDate(Date* d){
  //checks if the date is valid
  if (!d->getValidFlag() || numDates == MAX_DATES){
    delete d;
    return false;
  }

  int position = 0;


  //checks where it must be added
  for (int i = 0; i < numDates; i++){
    if (d->lessThan(dates[i])){
      break;
    } else{
      ++position;
    }
  }

  //shifts the other dates
  for (int i = numDates; i > position; i--){
    //should I be freeing stuff here?
    dates[i] = dates[i-1];
  }
  //puts it in the right spot
  dates[position] = d;
  ++numDates;
  return true;
}

void Calendar::merge(Calendar* c){
  //adds all of the dates of the parameter c to THIS calendar
  for(int i = 0; i < c->numDates; i++){
    Date* tempDate = new Date(*(c->dates[i]));
    addDate(tempDate);
  }
}

void Calendar::printDates(){
  //loops through and prints all the dates
  cout << "Printing out all of the dates in this calendar: \n\n";
  for (int i = 0; i < numDates; i++){
    dates[i]->print();
  }
}

void Calendar::print(){
  cout << "Calendar name: " << name << "\n";
  cout << "Number of dates: " << numDates << "\n";
  printDates();
}
