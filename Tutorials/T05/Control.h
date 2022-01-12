#ifndef CONTROL_H
#define CONTROL_H
#include "Client.h"
#include "Animal.h"

#define MAX_NUM_ARR 64

class Control
{
  public:
    Control();
    ~Control();
    bool add(Animal*);
    bool add(Client*);
    void printAnimals();
    void printClients();
    void launch();
    void initClientsTemp();
    void initAnimalsTemp();

  private:
    Animal** animals;
    int numAnimals;
    Client** clients;
    int numClients;

};

#endif
