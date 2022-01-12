#include <iostream>
#include <iomanip>
using namespace std;
#include <string>
#include "Record.h"

Record::Record(int y, string r, string s, string a, int nf, int na) : year(y), region(r), subRegion(s), animal(a), numFarms(nf), numAnimals(na) {}

int    Record::getYear()       const { return year;       }
string Record::getRegion()     const { return region;     }
string Record::getSubRegion()  const { return subRegion;  }
string Record::getAnimal()     const { return animal;     }
int    Record::getNumFarms()   const { return numFarms;   }
int    Record::getNumAnimals() const { return numAnimals; }

ostream& operator<<(ostream& output, Record& r){
  output<< setw(35)  << "Year: " << r.year << "Region: " << r.region << "Number of animals: " << r.numAnimals << endl;
  return output;
}
