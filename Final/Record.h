/*
  The purpose of this class is to represent a basic entity containing all of the information stored in a record. That is, all the information that is in a line of the farms.dat file.
*/
#ifndef RECORD_H
#define RECORD_H
#include <iostream>
using namespace std;
#include <string>


class Record
{
  friend ostream& operator<<(ostream&, Record&);

  public:
    Record(int, string, string, string, int, int);
    int getYear()         const;
    string getRegion()    const;
    string getSubRegion() const;
    string getAnimal()    const;
    int getNumFarms()     const;
    int getNumAnimals()   const;

  private:
    int year;
    string region;
    string subRegion;
    string animal;
    int numFarms;
    int numAnimals;

};

#endif
