#include <iostream>
using namespace std;
#include <string>
#include "Identifiable.h"

Identifiable::Identifiable(string letter, int* number)
{
  stringstream s;
  s << letter + "-" << *number;
  id = s.str();
  ++*number;
}

Identifiable::getId(){
  return id;
}
