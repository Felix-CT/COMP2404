/*
  The purpose of this class is to emulate a client of an animal shelter, and
  keeps track of the client's criteria for a new pet. It is also a derived class
  of the Identifiable class, which allows it to have a unique ID associated to it.
*/
#ifndef Client_H
#define Client_H
#include "string.h"
#include "Identifiable.h"
#include "CriteriaArray.h"

class Client : public Identifiable
{
  public:
    Client(string);
    string getName() const;
    CriteriaArray* getCriteria();
    void addCriteria(Criteria*);
    void print() const;

  protected:
    static int nextId;
    string name;
    CriteriaArray criteriaArr;

};

#endif
