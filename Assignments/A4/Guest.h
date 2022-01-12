/*
  The purpose of this class is to represent a guest that will be staying at the hotel.
*/
#ifndef GUEST_H
#define GUEST_H
#include <string>


class Guest
{
  public:
    Guest(string, bool=false);
    string getName()  const;
    bool getPremium() const;
    void print()      const;
    void addPts(int);

  private:
    string name;
    bool premium;
    int points;

};

#endif
