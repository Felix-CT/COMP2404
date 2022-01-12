/*
  The purpose of this class is to keep track of a date, and be compared to other
  dates.
*/
#ifndef DATE_H
#define DATE_H

class Date
{
  public:
    Date(int=0, int=0, int=2000);
    void setDate(int, int, int);
    void print();
    bool greaterThan(Date*);
    bool equals(Date*);

  private:
    int day;
    int month;
    int year;
    int  lastDayInMonth();
    bool leapYear();
    string getMonthStr() const;
};

#endif
