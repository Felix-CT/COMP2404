#ifndef Client_H
#define Client_H
#include "string.h"
#include "Identifiable.h"
#include "CriteriaArray.h"

class Client : public Indentifiable
{
  public:
    Client(string);
    string getName() const;
    CriteriaArray* getCriteria() const;
    void addCriteria(Criteria*);

  private:

  protected:
    //might have to change this up
    int nextId;
    string name;
    CriteriaArray criteriaArr;


};

#endif
