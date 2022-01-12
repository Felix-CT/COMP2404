#include <iostream>
using namespace std;
#include <string>

Control::Control(){
  Animal* animals[MAX_NUM_ARR];
  Client* clients[MAX_NUM_ARR];
}

Control::~Control(){
  //I don't think we allocate any memory in this tutorial
}

bool Control::add(Animal* animal){
  if (numAnimals == MAX_NUM_ARR){
    return false;
  }else {
    animals[numAnimals++] = animal;
    return true;
  }
}

bool Control::add(Client* client){
  if (numClients == MAX_NUM_ARR){
    return false;
  }else {
    Clients[numClients++] = client;
    return true;
  }
}

void Control::printAnimals(){
  for (int i = 0; i < numAnimals; i++){
    animals[i]->print();
  }
}

void Control::printClients(){
  for (int i = 0; i < numClients; i++){
    animals[i]->print();
  }
}

void Control::launch(){
  initClientsTemp();
  initAnimalsTemp();
  printClients();
  printAnimals();
}

void Control::initClientsTemp()
{
  Client* c;

  c  = new Client("Lee");
  c->addCriteria(new Criteria("Species", "Dog"));
  c->addCriteria(new Criteria("Gender", "F", 8));
  c->addCriteria(new Criteria("Age", "4", 2));
  add(c);

  c = new Client("Kara");
  c->addCriteria(new Criteria("Species", "Other"));
  c->addCriteria(new Criteria("Breed", "Guinea Pig", 9));
  c->addCriteria(new Criteria("Age", "2", 1));
  add(c);

  c = new Client("Laura");
  c->addCriteria(new Criteria("Species", "Cat"));
  c->addCriteria(new Criteria("Breed", "Domestic Short Hair", 2));
  c->addCriteria(new Criteria("Gender", "M", 3));
  c->addCriteria(new Criteria("Age", "1", 5));
  add(c);
}

void Control::initAnimalsTemp()
{
  add(new Animal(C_DOG, "Poodle", "White", "Betsy", "F", 5));
  add(new Animal(C_DOG, "Labradoodle", "Tan", "Killer", "F", 3));
  add(new Animal(C_DOG, "German Shepard", "Black/Tan", "Fluffy", "M", 2));
  add(new Animal(C_DOG, "Pug", "Tan", "Leon", "M", 4));
  add(new Animal(C_DOG, "Pug", "Tan", "Lily", "F", 1));
  add(new Animal(C_CAT, "Domestic Short Hair", "Grey", "Lady", "F", 11));
  add(new Animal(C_CAT, "Domestic Short Hair", "Grey", "Shadow", "M", 5));
  add(new Animal(C_CAT, "Domestic Long Hair", "Grey", "Luka", "M", 7));
  add(new Animal(C_CAT, "Domestic Short Hair", "Grey tabby", "Fiona", "F", 8));
  add(new Animal(C_CAT, "Domestic Short Hair", "Brown tabby", "Ruby", "F", 5));
  add(new Animal(C_RABBIT, "Lionhead", "Black", "Ziggy", "F", 3));
  add(new Animal(C_OTHER, "Guinea Pig", "Black", "Quark", "M", 9));
  add(new Animal(C_OTHER, "Guinea Pig", "Brown", "Quasar", "M", 1, 4));
  add(new Animal(C_OTHER, "Mouse", "Tan", "Pecorino", "M", 0, 3));
  add(new Animal(C_OTHER, "Mouse", "Tan", "Gruyere", "M", 0, 3));
  add(new Animal(C_OTHER, "Mouse", "Tan", "Limburger", "M", 0, 3));
}
