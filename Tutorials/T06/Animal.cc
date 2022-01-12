#include <iostream>
using namespace std;
#include <string>
#include "Animal.h"

int Animal::nextId = 1001;

Animal::Animal(string name, string breed, string gender, string colour, SpeciesType species, int years, int months) : Identifiable("A", nextId);
{
  this->name = name;
  this->breed = breed;
  this->gender = gender;
  this->colour = colour;
  this->species = species;
  this-> age = months + years*12;

}

string Animal::getName(){
  return name;
}

string Animal::getBreed(){
  return breed;
}

string Animal::getGender(){
  return gender;
}

int Animal::getAge(){
  return age;
}

void print(){
  cout << "Printing out the animal's data:\n";
  cout << "Name: " << name << endl;
  cout << "Id: " << nextId;
  cout << "Breed: " << breed << endl;
  cout << "Gender: " << gender << endl;
  cout << "Age: " << age / 12 << " years and " << age % 12 << " months.\n" <<endl;
}
