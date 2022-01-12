/*
  The purpose of this class is to keep track of multiple criteria.
*/

#ifndef DYNARRAY_H
#define DYNARRAY_H

#include "Criteria.h"
#include "defs.h"


class CriteriaArray
{
  public:
    CriteriaArray();
    ~CriteriaArray();
    void      add(Criteria*);
    int       getSize() const;
    Criteria* get(int);
    void      print()   const;

  private:
    Criteria* elements[MAX_SIZE];
    int       size;
};

#endif
