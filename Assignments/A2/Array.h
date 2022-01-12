/*
  The purpose of this class is to implement an array-like structure, but with
  extra functionalities. This one allows the user to store call objects.
*/


#ifndef ARRAY_H
#define ARRAY_H

#define MAX_ARR 64

#include "Call.h"

class Array
{
public:
    Array();
    Array(Array&);
    ~Array();
    bool add(Call*);
    void print();
    bool add(Array&);
    Call* get(int);
    int getNumCalls();
    void cleanup();

private:
    Call** calls;
    int numCalls;
};

#endif
