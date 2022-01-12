#include <iostream>
using namespace std;
#include <string>
#include "Match.h"


Animal::Animal(Animal* a, Client* c, float s);
{
  animal = a;
  client = c;
  score = s
}

Match::getScore(){
  return score;
}

Match::getClientId(){
  return client->getId();
}

Match::getAnimalId(){
  return animal->getId();
}

void print(){
  cout << "Printing out the match information\n";
  cout << "Animal name: " << animal->getName(); << endl;
  cout << "Animal ID: " << animal->getId() << endl;
  cout << "Client name: " << client->getName(); << endl;
  cout << "Client ID: " << client->getId() << endl;
  cout << "Score: " << score << "/20" << endl;
  cout << "Match percentage: " << score / 20 << "%\n";
}
