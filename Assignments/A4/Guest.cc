#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#include "Guest.h"


Guest::Guest(string name, bool premium) : name(name),  premium(premium), points(0) {}

string Guest::getName()  const { return name; }
bool Guest::getPremium() const { return premium; }

void Guest::print() const {
	cout << "-- " << left << setfill(' ') << setw(9) << name;
	if (premium) {
		cout << "Premium guest:";
	}
	else {
		cout << "Regular guest:";
	}
	cout << right << setfill(' ') << setw(7) << points << " pts\n";

}

void Guest::addPts(int num) {
  points += num;
}
