/*
  The purpose of this class is to implement a map specific to this program, with the purpose of storing Records with different possibilities for keys.
*/
#ifndef MAP_H
#define MAP_H
#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include "Record.h"

template <class T>
class Map
{
  public:
    vector<T> keys;
    vector<vector<Record*>> values;
    void add(T, Record*);
    int getNumKeys() const;
    vector<T> getKeys();
    vector<Record*> operator[](T var);

};

template <class T>
void Map<T>::add(T key, Record* rec){
  for (size_t i = 0; i < keys.size(); i++){
     if (keys[i] == key){
       values[i].push_back(rec);
       return;
     }
  }

  keys.push_back(key);
  vector<Record*> v;
  v.push_back(rec);
  values.push_back(v);
  return;
}

template <class T>
int Map<T>::getNumKeys() const {
  return keys.size();
}

template <class T>
vector<T> Map<T>::getKeys(){
  return keys;
}

template <class T>
vector<Record*> Map<T>::operator[](T var){
  for (size_t i = 0; i < keys.size(); i++){
    if (keys[i] == var){
      return values[i];
    }
  }
  return values[0];
}
#endif
