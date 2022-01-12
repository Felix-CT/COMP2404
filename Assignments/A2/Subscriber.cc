#include <iostream>
using namespace std;

#include "Subscriber.h"

Subscriber::Subscriber(string s) {
	phoneNum = s;
	inCalls = new Array();
	outCalls = new Array();
}


Subscriber::~Subscriber() {
	delete inCalls;
	delete outCalls;
}

bool Subscriber::addIncoming(Call* c) {
	return inCalls->add(c);
}

bool Subscriber::addOutgoing(Call* c) {
	return outCalls->add(c);
}

string Subscriber::getPhoneNum() {
	return phoneNum;
}

Array* Subscriber::getInCalls() {
	return inCalls;
}

Array* Subscriber::getOutCalls() {
	return outCalls;
}

void Subscriber::print()
{
	cout << "Subscriber " << phoneNum << ":\n";

	Array tempArr{ *inCalls };
	tempArr.add(*outCalls);

	tempArr.print();

	cout << endl;
}
