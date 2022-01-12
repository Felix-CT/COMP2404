/*
  The purpose of this class is to serve as a collection class for ReportRow objects. It additionally contains a compareBehaviour object which determines how the elements will be sorted.
*/
#ifndef REPORTDATA_H
#define REPORTDATA_H
#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include <vector>
#include "CompareBehaviour.h"

template <class T>
class ReportData
{
  template<class C>
  friend ostream& operator<<(ostream&, const ReportData<C>& report);
  public:
    ReportData(CompareBehaviour<T>* b) : behaviour(b) {};
    ~ReportData();
    void add(T, string);


  private:
    template <class V>
    class ReportRow
    {
      public:
        ReportRow(V key, string s) : key(key), row(s) {};
        V key;
        string row;
    };

    vector<ReportRow<T>> rows;
    CompareBehaviour<T>* behaviour;
};

template<class T>
inline ReportData<T>::~ReportData()
{
    delete behaviour;
}

template <class T>
void ReportData<T>::add(T key, string row){
  typename vector<ReportRow<T>>::iterator itr;

  for (itr = rows.begin(); itr != rows.end(); ++itr){
    if (behaviour->compare(itr->key, key)){
      rows.insert(itr, ReportRow<T>(key, row));
      return;
    }
  }
  rows.insert(itr, ReportRow<T>(key, row));
}

template <class C>
ostream& operator<<(ostream& output, const ReportData<C>& report){
  for (int i = 0; i < report.rows.size(); i++){
    output << report.rows.at(i).row << endl;
  }
  return output;
}
#endif
