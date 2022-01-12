/*
  The purpose of this class is to represent criteria that a client may have when
  trying to adopt an animal.
*/

#ifndef CRITERIA_H
#define CRITERIA_H

#include <string>
using namespace std;

class Criteria
{
  public:
    Criteria(string="", string="", int=0);

    string getName() const;
    string getValue() const;
    int    getWeight() const;
    void   print() const;

  private:
    string name;
    string value;
    int    weight;
};

#endif
