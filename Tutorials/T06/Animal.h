#ifndef Animal_H
#define Animal_H
#include "string.h"
#include "Identifiable.h"

class Animal : public Indentifiable
{
  public:
    Animal(string, string, string, string, SpeciesType, int int);
    string getName() const;
    string getBreed() const;
    string getGender() const;
    string getAge() const;
    void print() const;


  private:

  protected:
    //might have to change this up
    int nextId;
    string name;
    string breed;
    string gender;
    string colour;
    SpeciesType species;
    int age;

};

#endif
