#ifndef Identifiable_H
#define Identifiable_H
#include "string.h"

class Identifiable
{
  public:
    Identifiable(string, int*);
    getId();


  private:

  protected:
    string id;
    string letter;

};

#endif
