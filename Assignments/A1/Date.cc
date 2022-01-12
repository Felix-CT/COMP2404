#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"


Date::Date(string n, int d, int m, int y, int h, int min, int duration, bool recur, int numRecur)
{
  eventName = n;
  recurring = recur;
  //sets the number of recurrences depending on if the event is recurring
  numRecurring = (recurring ? numRecur : 0);

  //checks to see if there is an invalid value, and if so, it sets the invalid
  //values to the default values.
  if (!(valid = validate(d, m, y, h, min, duration))){
    fixInvalids(d, m, y, h, min, duration);
  }
  //can be set after the time is validated
  startTime = (60 * h) + min;
  this->duration = duration;

  //initializing the day, month, year
  setDate(d, m, y);
}

//copy constructor
Date::Date(Date& oldDate)
{
  eventName = oldDate.eventName;
  day = oldDate.day;
  month = oldDate.month;
  year = oldDate.year;
  startTime = oldDate.startTime;
  duration = oldDate.duration;
  recurring = oldDate.recurring;
  numRecurring = oldDate.numRecurring;
  valid = oldDate.valid;
}

void Date::setDate(int d,int m,int y)
{
  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12 ) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth() ) ? d : 0 );
}

bool Date::validate(int d, int m, int y, int h, int min, int duration){
  //setDate(d, m, y);
  if (m <= 0 || m > 12){return false;}
  if (y <= 0){return false;}
  //since we check to see if the year and month are valid first, we know that
  // these two parameters must be valid when the checkMonthLength() function is called.
  if (d <= 0 || d > checkMonthLength(m, y)){return false;}
  if (h < 0 || h > 23){return false;}
  if (min < 0 || min > 59){return false;}
  if (duration < 1){return false;}
  if (numRecurring < 0){return false;}

  return true;
}

void Date::fixInvalids(int d, int m, int y, int h, int min, int duration){
  //setting invalid values to defaults
  if (h < 0 || h > 23){h = 0;}
  if (min < 0 || min >59){min = 0;}
  startTime = (60 * h) + min;
  if (duration < 1){duration = 1;}
  if (numRecurring < 0){numRecurring = 0;}
}


bool Date::lessThan(Date *d){
  //checks all of the measures of time to determine if it is less than d
  if (d->year > year){
    return true;
  }else if (d->year == year){
    if (d->month > month){
      return true;
    }else if (d->month == month){
      if (d->day > day){
        return true;
      }else if (d->day == day){
        if (d->startTime > startTime){
          return true;
        }
      }
    }
  }
  //if it is not less than d, return false
  return false;
}


bool Date::getRecurFlag(){
  return recurring;
}


bool Date::getValidFlag(){
  return valid;
}

void Date::print(){
  cout << "Name of event: " << eventName << "\n";
  cout << "Day of event: " << day << '\n';
  cout << "Month of event: " << month << '\n';
  cout << "Year of event: " << year << '\n';

  //calculates the starting minute and hour
  int hour = startTime / 60;
  int min = startTime % 60;

  //creates strings to display the starting time
  string startHour = ((hour > 9) ? to_string(hour) : "0" + to_string(hour));
  string startMin = ((min > 9) ? to_string(min) : "0" + to_string(min));

  cout << "Start time of event: " << startHour + ":" + startMin << '\n';

  //caulculates the time the event will end
  int endH = hour + (min + duration )/ 60;
  int endM = (min + duration) % 60;

  //creates strings to display the ending time
  string endHour = ((endH > 9) ? to_string(endH) : "0" + to_string(endH));
  string endMin = ((endM > 9) ? to_string(endM) : "0" + to_string(endM));

  cout << "End time of event: " << endHour + ":" + endMin << '\n';

  string validity = ((valid) ? "valid" : "invalid");
  cout << "validity of the date: " << validity << "\n";

  if (recurring){
    cout << "The event reoccurs " << to_string(numRecurring) << " times.\n\n";
  }else{
    cout << "The event is non-recurring.\n\n";
  }
}


int Date::checkMonthLength(int m, int y){
  //find the last day of the current month
  switch(m)
  {
    case 2:
      if (checkLeapYear(y))
        return 29;
      else
        return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30;
  }
}

bool Date::checkLeapYear(int y){
  //finds if the current year is a leap year
  if ( y%400 == 0 ||
       (y%4 == 0 && y%100 != 0) )
    return true;
  else
    return false;
}



int Date::lastDayInMonth(){
  //find the last day of the current month
  switch(month)
  {
    case 2:
      if (leapYear())
        return 29;
      else
        return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30;
  }
}

bool Date::leapYear(){
  //finds if the current year is a leap year
  if ( year%400 == 0 ||
       (year%4 == 0 && year%100 != 0) )
    return true;
  else
    return false;
}

string Date::getMonthStr(){
  //returns the name of the current month as a string
  string monthStrings[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December" };

  if ( month >= 1 && month <= 12 )
    return monthStrings[month-1];
  else
    return "Unknown";
}
