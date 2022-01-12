#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#include "Client.h"

int Client::nextId = 7001;

Client::Client(string name) : Identifiable("C", &nextId)
{
  this->name = name;
  criteriaArr = CriteriaArray();
}

string Client::getName() const { return name; }
CriteriaArray* Client::getCriteria() { return &criteriaArr; }

void Client::addCriteria(Criteria* c){
  criteriaArr.add(c);
}


void Client::print() const {
  cout << left << setfill(' ');
  cout << setw(8) << id;
  cout << name << endl;
  criteriaArr.print();
}
