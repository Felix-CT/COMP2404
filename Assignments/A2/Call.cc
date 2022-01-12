#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Call.h"

Call::Call(string source, string destination, int duration, int day, int month, int year, int hours, int minutes)
{
  this->src = source;
  this->dest = destination;
  this->duration = duration;

  this->startDate = new Date(day, month, year);
  this->startTime = new Time(hours, minutes);

}

Call::~Call()
{
  delete this->startDate;
  delete this->startTime;
}

bool Call::greaterThan(Call* c){
	return ((startDate->greaterThan(c->startDate)) || ((startDate->equals(c->startDate)) && (startTime->greaterThan(c->startTime))));
}

string Call::getSrc(){
  return src;
}

string Call::getDest(){
  return dest;
}

void Call::print(){
  this->startDate->print();
  this->startTime->print();
  cout << ",  ";
  cout << setfill(' ') << setw(2) << this->duration << " mins:  ";
  cout << "From: " << this->src << "  ";
  cout << "To: " << this->dest << endl;
}
