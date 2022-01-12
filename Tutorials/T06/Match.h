#ifndef Match_H
#define Match_H
#include "string.h"
#include "Animal.h"
#include "Client.h"

class Match
{
  public:
    Match(Animal*, Client*, float);
    float getScore();
    int getClientId();
    int getAnimalId();
    void print();

  private:
    Animal* animal;
    Client* client;
    float score;
};

#endif
