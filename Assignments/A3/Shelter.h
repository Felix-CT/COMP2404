/*
  The purpose of this class is to emulate a shelter which has animals, and
  clients that are interested in adopting the animals.
*/

#ifndef SHELTER_H
#define SHELTER_H
#include "string.h"
#include "Animal.h"
#include "Client.h"
#include "MatchListByScore.h"
#include "MatchListByClient.h"
#include "defs.h"

class Shelter
{
  public:
    Shelter(string);
    ~Shelter();
    void printAnimals() const;
    void printClients() const;
    void computeMatches(MatchListByScore&, MatchListByClient&);
    bool add(Animal*);
    bool add(Client*);


  private:
    string name;
    Animal** animals;
    int numAnimals;
    Client** clients;
    int numClients;
    float findScore(Animal*, Client*);

};

#endif
