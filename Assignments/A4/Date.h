/*
  The purpose of this class is to represent the date to be used by a reservation.
*/
#ifndef DATE_H
#define DATE_H

class Date
{
  public:
    Date(int=0, int=0, int=2000);
    Date(Date&);
    ~Date();
    void setDate(int, int, int);
    void print() const;
    bool lessThan(Date&);
    bool equals(Date &);
    void add(int);

  private:
    int day;
    int month;
    int year;
    int  lastDayInMonth();
    bool leapYear();
    string getMonthStr() const;
};

#endif
