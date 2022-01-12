#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#include "Animal.h"

int Animal::nextId = 1001;

Animal::Animal(SpeciesType species, string breed, string colour, string name, string gender, int years, int months) : Identifiable("A", &nextId)
{
  this->name = name;
  this->breed = breed;
  this->gender = gender;
  this->colour = colour;
  this->species = species;
  this-> age = months + years*12;
}

string Animal::getName()    const { return name; }
string Animal::getBreed()   const { return breed; }
string Animal::getGender()  const { return gender; }
int Animal::getAge()        const { return age; }


string Animal::getSpecies() const {

  switch (species) {
    case C_DOG:
      return "Dog";
      break;
    case C_CAT:
      return "Cat";
      break;
    case C_BIRD:
      return "Bird";
      break;
    case C_RABBIT:
      return "Rabbit";
      break;
    case C_OTHER:
      return "Other";
      break;
  }
  return "Error";
}

void Animal::print() const {
  cout << left << setfill(' ');
  cout << setw(8) << id;
  cout << setw(10) << getSpecies();
  cout << setw(22) << breed;
  cout << setw(4) << gender;
  cout << setw(20) << name;
  cout << setw(12) << colour;
  cout << right << setw(6) << age / 12 << "y, " << age % 12 << "m\n";
}
