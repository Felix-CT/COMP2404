#include <iostream>
using namespace std;
#include <string>
#include "Client.h"

int Client::nextId = 1001;

Client::Client(string name) : Identifiable("C", nextId);
{
  this->name = name;
}

string Client::getName(){
  return name;
}

CriteriaArray* Client::getCriteria(){
  return &CriteriaArray;
}
void Client::addCriteria(Criteria* c){
  criteriaArr.add(c);
}


void print(){
  cout << "Printing the client's information: \n";
  cout << "Name: " << name;
  cout << "Id: " << nextId;
  cout << "All criteria: ";
  criteriaArr.print();
}
