#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"

Date::Date(int d, int m, int y)
{
  setDate(d, m, y);
}

Date::Date(Date& d){
  day = d.day;
  month = d.month;
  year = d.year;
}

Date::~Date()
{
}


bool Date::lessThan(Date& d){
  if (year < d.year){
    return true;
  }else if (year == d.year){
    if (month < d.month){
      return true;
    }else if (month == d.month){
      if (day < d.day){
        return true;
      }
    }
  }
  return false;
}

bool Date::equals(Date& d){
  return (year == d.year && month == d.month && day == d.day);
}

void Date::print() const {
  cout << setfill('0') << setw(4) << year;
  cout << '-' << setfill('0') << setw(2) << month;
  cout << '-' << setfill('0') << setw(2) << day;
}

void Date::add(int duration){
  if (day + duration <= lastDayInMonth()){
    day += duration;
  }else {
    if (month + 1 <= 12){
      ++month;
      day += duration;
      day -= lastDayInMonth();
    }else{
      ++year;
      month = 1;
      day += duration;
      day -= lastDayInMonth();
    }
  }
}





void Date::setDate(int d,int m,int y)
{
  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth() ) ? d : 0 );
}

int Date::lastDayInMonth()
{
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

bool Date::leapYear()
{
  if ( year%400 == 0 ||
       (year%4 == 0 && year%100 != 0) )
    return true;
  else
    return false;
}

string Date::getMonthStr() const
{
  string monthStrings[] = {
    "January", "Februrary", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December" };

  if ( month >= 1 && month <= 12 )
    return monthStrings[month-1];
  else
    return "Unknown";
}
