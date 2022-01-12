#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

#include "Criteria.h"

Criteria::Criteria(string n, string v, int w)
  : name(n), value(v), weight(w) { }

string Criteria::getName()        const { return name;   }
string Criteria::getValue()       const { return value;  }
int    Criteria::getWeight()      const { return weight; }

void Criteria::print() const
{
  cout << setw(8)  << left  << name   << " "
       << setw(20) << left  << value  << " "
       << setw(2)  << right << weight << " " << endl;
}
