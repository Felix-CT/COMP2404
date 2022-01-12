#ifndef DATE_H
#define DATE_H

class Date
{
  public:

    Date(string, int, int, int, int, int, int, bool = false, int = 10);
    Date(Date&);
    void setDate(int,int,int);
    bool getRecurFlag();
    bool getValidFlag();
    void print();
    bool lessThan(Date *d);

  private:
    int day;
    int month;
    int year;
    string eventName;
    int startTime;
    int duration;
    bool recurring;
    int numRecurring;
    bool valid;
    int  lastDayInMonth();
    bool leapYear();
    int checkMonthLength(int m, int y);
    bool checkLeapYear(int y);
    string getMonthStr();
    bool validate(int d, int m, int y, int h, int min, int duration);
    void fixInvalids(int d, int m, int y, int h, int min, int duration);
};

#endif
