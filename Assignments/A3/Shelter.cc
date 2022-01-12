#include <iostream>
#include <sstream>
using namespace std;
#include <string>
#include <cstdlib>
#include "Shelter.h"

Shelter::Shelter(string name)
{
  animals = new Animal* [MAX_SIZE];
  clients = new Client* [MAX_SIZE];
  this->name = name;
  numAnimals = 0;
  numClients = 0;
}

Shelter::~Shelter(){
  for (int i = 0; i < numAnimals; i++){
    delete animals[i];
  }
  for (int i = 0; i < numClients; i++){
    delete clients[i];
  }
  delete [] animals;
  delete [] clients;
}

bool Shelter::add(Animal* animal){
  if (numAnimals == MAX_SIZE){
    return false;
  }else {
    animals[numAnimals++] = animal;
    return true;
  }
}

bool Shelter::add(Client* client){
  if (numClients == MAX_SIZE){
    return false;
  }else {
    clients[numClients++] = client;
    return true;
  }
}

void Shelter::printAnimals() const {
  cout << "ANIMALS:\n";
  for (int i = 0; i < numAnimals; i++){
    animals[i]->print();
  }
}

void Shelter::printClients() const {
  cout << "CLIENTS:\n";
  for (int i = 0; i < numClients; i++){
    clients[i]->print();
  }
}

void Shelter::computeMatches(MatchListByScore& scoreList, MatchListByClient& clientList){
  for (int i = 0; i < numAnimals; i++) {
    for (int j = 0; j < numClients; j++) {
      float score = findScore(animals[i], clients[j]);
      if (score > 0){
        Match* match = new Match(animals[i], clients[j], score);
        scoreList.add(match);
        clientList.add(match);
      }
    }
  }
  cout << "MATCHES BY SCORE:\n";
  scoreList.print();
  cout << endl << "MACTCHES BY CLIENT:\n";
  clientList.print();
}

float Shelter::findScore(Animal* animal, Client* client){
  float score = 0.0;

  for (int i = 0; i < client->getCriteria()->getSize(); i++){
    string cName = client->getCriteria()->get(i)->getName();
    if (cName == "Species"){
      if (animal->getSpecies() == client->getCriteria()->get(i)->getValue()){
        score += 10;
      }
    }else if (cName == "Breed"){
      if (animal->getBreed() == client->getCriteria()->get(i)->getValue()){
        score += client->getCriteria()->get(i)->getWeight();
      }
    }else if (cName == "Gender"){
      if (animal->getGender() == client->getCriteria()->get(i)->getValue()){
        score += client->getCriteria()->get(i)->getWeight();
      }
    }else if (cName == "Age"){
      //do we assume it's always gonna be an int? or can it be a float?
      float cYears;
      string s = client->getCriteria()->get(i)->getValue();
      stringstream ss;
      ss << s;
      ss >> cYears;
      float aYears = animal->getAge() / 12;
      float result = abs(aYears - cYears) / 10;

      if (result > 1){
        result = 1;
      }
      score += client->getCriteria()->get(i)->getWeight() * (1 - result);
    }
  }
  return score;
}
