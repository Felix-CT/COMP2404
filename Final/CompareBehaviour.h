/*
  The purpose of this class is to decide how items will be compared when added to a collection. This was specifically used for the ReportData Objects to sort ReportRow objects, but can be used for other classes if desired.
*/
#ifndef COMPAREBEHAVIOUR_H
#define COMPAREBEHAVIOUR_H
#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>

template <class T>
class CompareBehaviour {
  public:
    virtual bool compare(T, T) const =0;
    virtual ~CompareBehaviour() {}
};

template <class T>
class AscBehaviour : public CompareBehaviour<T> {
  public:
    bool compare(T, T) const;
    ~AscBehaviour() {}
};

template <class T>
class DescBehaviour : public CompareBehaviour<T> {
  public:
    bool compare(T, T) const;
    ~DescBehaviour() {}
  };

template <class T>
bool AscBehaviour<T>::compare(T x1, T x2) const{
  return x1 >= x2;
}

template <class T>
bool DescBehaviour<T>::compare(T x1, T x2) const{
  return x1 <= x2;
}
#endif
