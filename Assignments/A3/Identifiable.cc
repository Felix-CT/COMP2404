#include <iostream>
using namespace std;
#include <string>
#include <sstream>
#include "Identifiable.h"

Identifiable::Identifiable(string letter, int* number)
{
  stringstream s;
  s << letter + "-" << *number;
  id = s.str();
  ++*number;
}

string Identifiable::getId() const {
  return id;
}
