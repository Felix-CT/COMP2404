/*
  The purpose of this class is to keep track of a  Subscriber, which has a phone
  number, as well as the calls it has made and received.
*/

#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#define MAX_ARR 64

#include "Call.h"
#include "string.h"
#include "Array.h"

class Subscriber
{
  public:
    Subscriber(string);
    ~Subscriber();
    bool addIncoming(Call*);
    bool addOutgoing(Call*);
    void print();
    Array* getInCalls();
    Array* getOutCalls();
    string getPhoneNum();


  private:
    string phoneNum;
    Array* inCalls;
    Array* outCalls;
};

#endif
