/*
  The purpose of this class is to represent a possible match between an Animal
  and a Client, and to keep track of the score of said match.
*/

#ifndef Match_H
#define Match_H
#include "string.h"
#include "Animal.h"
#include "Client.h"

class Match
{
  public:
    Match(Animal*, Client*, float);
    float getScore() const;
    string getClientId() const;
    string getAnimalId() const;
    void print() const;

  private:
    Animal* animal;
    Client* client;
    float score;
};

#endif
