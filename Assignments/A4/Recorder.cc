#include <iostream>
using namespace std;
#include "Recorder.h"

Recorder::Recorder(string n) : name(n){}

void Recorder::printRecords() const {
  cout << "\nRecords for " << name << " Recorder" << endl;
  for (int i = 0; i < records.size()-1; i++){
    if (records[i] != "") {
      cout << name << " Recorder:   ";
      cout << records[i];
    }
  }
  if (records[records.size()-1] != "") {
      cout << name << " Recorder:   ";
      cout << records[records.size() - 1] << endl;
  }
}
