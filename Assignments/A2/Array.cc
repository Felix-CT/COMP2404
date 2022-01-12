#include <iostream>
using namespace std;

#include "Array.h"

Array::Array() {
    numCalls = 0;
    calls = new Call * [MAX_ARR];
}

Array::Array(Array& oldArray) {
    numCalls = 0;
    calls = new Call* [MAX_ARR];
    add(oldArray);
}

Array::~Array()
{
    delete[] calls;
}

bool Array::add(Call* c)
{
    if (numCalls == MAX_ARR) {
        delete c;
        return false;
    }

    int position = 0;

    for (int i = 0; i < numCalls; i++) {
        if (c->greaterThan(calls[i])) {
            break;
        }
        else {
            ++position;
        }
    }

    for (int i = numCalls; i > position; i--) {
        calls[i] = calls[i - 1];
    }
    calls[position] = c;
    ++numCalls;
    return true;
}

bool Array::add(Array& arr) {
    for (int i = 0; i < arr.numCalls; i++) {
        if (!add(arr.get(i))) {
            return false;
        }
    }
    return true;
}

void Array::cleanup() {
    for (int i = 0; i < numCalls; i++) {
        delete calls[i];
    }
}

int Array::getNumCalls() {
    return numCalls;
}

Call* Array::get(int i) {
    return calls[i];
}

void Array::print()
{
    for (int i = 0; i < numCalls; ++i)
        calls[i]->print();
}
