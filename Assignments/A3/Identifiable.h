/*
  The purpose of this class is to prove a base class for any derived class that
  requires an id.
*/

#ifndef Identifiable_H
#define Identifiable_H
#include "string.h"

class Identifiable
{
  public:
    Identifiable(string, int*);
    string getId() const;

  protected:
    string id;

};

#endif
