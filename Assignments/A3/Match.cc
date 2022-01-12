#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#include "Match.h"


Match::Match(Animal* a, Client* c, float s)
{
  animal = a;
  client = c;
  score = s;
}

float Match::getScore() const { return score; }
string Match::getClientId() const { return client->getId(); }
string Match::getAnimalId() const { return animal->getId(); }

void Match::print() const {
  cout << left << setfill(' ');
  cout << setw(7) << client->getId();
  cout << setw(10) << client->getName();
  cout << setw(3) << ":";
  cout << setw(7) << animal->getId();
  cout << setw(10) << animal->getName();
  cout << setw(5) << ":";
  cout << right << setw(5) << fixed <<setprecision(1) << score << " " << "("  << setprecision(0)  << setw(3) << score *5 << "%)" <<endl;
}
