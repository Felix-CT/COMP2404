#ifndef Identifiable_H
#define Identifiable_H
#include "string.h"

class Identifiable
{
  public:
    Identifiable(string, int*);
    getId() const;


  private:

  protected:
    string id;
    string letter;

};

#endif
