/*
  The purpose of this class is to emulate an animal, and contains characteristics
  than an animal would have. It is also a derived class of the Identifiable class,
  which allows it to have a unique ID associated to it.
*/

#ifndef ANIMAL_H
#define ANIMAL_H
#include "string.h"
#include "Identifiable.h"
#include "defs.h"

class Animal : public Identifiable
{
  public:
    Animal(SpeciesType, string, string, string, string, int, int=0);
    string getName() const;
    string getBreed() const;
    string getGender() const;
    string getSpecies() const;
    int getAge() const;
    void print() const;

  protected:
    static int nextId;
    string name;
    string breed;
    string gender;
    string colour;
    SpeciesType species;
    int age;

};

#endif
