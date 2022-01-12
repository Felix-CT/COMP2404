#include <iostream>
using namespace std;

#include "Telco.h"

Telco::Telco(string n) {
    name = n;
    numSubs = 0;
    subs = new Subscriber * [MAX_NUM_SUBS];
    allCalls = new Array();
}


Telco::~Telco() {
    allCalls->cleanup();
    delete allCalls;
    for (int i = 0; i < numSubs; i++) {
        delete subs[i];
    }
    delete[] subs;
}

void Telco::addSub(Subscriber* s) {
    if (numSubs < MAX_NUM_SUBS) {
        subs[numSubs++] = s;
    }
}

bool Telco::addCall(string srcNum, string destNum, int year, int month, int day, int hour, int minute, int duration) {
    Call* newCall = new Call(srcNum, destNum, duration, day, month, year, hour, minute);
    bool callUsed = false;

    for (int i = 0; i < numSubs; i++) {
        if (subs[i]->getPhoneNum() == srcNum || subs[i]->getPhoneNum() == destNum) {
            if (!callUsed) {
                allCalls->add(newCall);
                callUsed = true;
            }

            if (subs[i]->getPhoneNum() == srcNum) {
                subs[i]->addOutgoing(newCall);
            }
            else {
                subs[i]->addIncoming(newCall);
            }
        }
    }
    if (!callUsed) {
        delete newCall;
    }
    return callUsed;
}

void Telco::computeFreqCaller(string destNum) {
    if (destNum == "all") {
        string freqCallers[MAX_NUM_SUBS];
        int highestNumCalls = 0;
        int numHighestCallers = 0;
        for (int i = 0; i < numSubs; i++) {
            if (subs[i]->getOutCalls()->getNumCalls() > highestNumCalls) {
                highestNumCalls = subs[i]->getOutCalls()->getNumCalls();
                numHighestCallers = 1;
                freqCallers[0] = subs[i]->getPhoneNum();
            }
            else if (subs[i]->getOutCalls()->getNumCalls() == highestNumCalls) {
                freqCallers[numHighestCallers++] = subs[i]->getPhoneNum();
            }
        }
        printFreqCallersAll(freqCallers, numHighestCallers);


    }
    else {
        bool found = false;
        int pos = 0;
        for (int i = 0; i < numSubs; i++) {
            if (subs[i]->getPhoneNum() == destNum) {
                found = true;
                pos = i;
                break;
            }
        }

        if (found) {
            Array* inCalls = subs[pos]->getInCalls();
            bool inMap = false;

            string callStrings[MAX_ARR];
            int callValues[MAX_ARR];
            int mapPos = 0;
            for (int i = 0; i < inCalls->getNumCalls(); i++) {
                inMap = false;

                for (int j = 0; j < mapPos; j++) {
                    if (callStrings[j] == inCalls->get(i)->getSrc()) {
                        callValues[j]++;
                        inMap = true;
                        break;
                    }
                }
                if (!inMap) {
                    callStrings[mapPos] = inCalls->get(i)->getSrc();
                    callValues[mapPos++] = 1;
                }
            }

            string freqCallers[MAX_ARR];
            int highestNumCalls = 0;
            int numHighestCallers = 0;

            for (int i = 0; i < mapPos; i++) {
                if (callValues[i] > highestNumCalls) {
                    freqCallers[0] = callStrings[i];
                    numHighestCallers = 1;
                    highestNumCalls = callValues[i];
                }
                else if (callValues[i] == highestNumCalls) {
                    freqCallers[numHighestCallers++] = callStrings[i];
                }
            }
            if (numHighestCallers == 0) {
                cout << "This subscriber has not received any calls.\n\n";
            }
            else {
                printFreqCallers(freqCallers, numHighestCallers, destNum);
            }
        } else {
            cout << "ERROR: Could not find subscriber.\n";

            return;
        }
    }
}


void Telco::computeFreqCalled(string srcNum) {
    if (srcNum == "all") {
        string freqCalled[MAX_ARR];
        int highestNumCalls = 0;
        int numHighestCallers = 0;
        for (int i = 0; i < numSubs; i++) {
            if (subs[i]->getInCalls()->getNumCalls() > highestNumCalls) {
                highestNumCalls = subs[i]->getInCalls()->getNumCalls();
                numHighestCallers = 1;
                freqCalled[0] = subs[i]->getPhoneNum();
            }
            else if (subs[i]->getInCalls()->getNumCalls() == highestNumCalls) {
                freqCalled[numHighestCallers++] = subs[i]->getPhoneNum();
            }
        }
        printFreqCalledAll(freqCalled, numHighestCallers);


    }
    else {
        bool found = false;
        int pos = 0;
        for (int i = 0; i < numSubs; i++) {
            if (subs[i]->getPhoneNum() == srcNum) {
                found = true;
                pos = i;
                break;
            }
        }

        if (found) {
            Array* outCalls = subs[pos]->getOutCalls();
            bool inMap = false;

            string callStrings[MAX_ARR];
            int callValues[MAX_ARR];
            int mapPos = 0;
            for (int i = 0; i < outCalls->getNumCalls(); i++) {
                inMap = false;

                for (int j = 0; j < mapPos; j++) {
                    if (callStrings[j] == outCalls->get(i)->getDest()) {
                        callValues[j]++;
                        inMap = true;
                        break;
                    }
                }

                if (!inMap) {
                    callStrings[mapPos] = outCalls->get(i)->getDest();
                    callValues[mapPos++] = 1;
                }
            }

            string freqCalled[MAX_ARR];
            int highestNumCalls = 0;
            int numHighestCallers = 0;

            for (int i = 0; i < mapPos; i++) {
                if (callValues[i] > highestNumCalls) {
                    freqCalled[0] = callStrings[i];
                    numHighestCallers = 1;
                    highestNumCalls = callValues[i];
                }
                else if (callValues[i] == highestNumCalls) {
                    freqCalled[numHighestCallers++] = callStrings[i];
                }
            }

            if (numHighestCallers == 0) {
                cout << "This subscriber has not called anyone.\n\n";
            }
            else {
                printFreqCalled(freqCalled, numHighestCallers, srcNum);
            }
        }else {
            cout << "ERROR: Could not find subscriber.\n";
            return;
        }
    }
}


void Telco::printFreqCallers(string freqCallers[], int num, string dest) {
    for (int i = 0; i < numSubs; i++) {
        if (subs[i]->getPhoneNum() == dest) {
            for (int x = 0; x < num; x++) {
                cout << "==> Most frequent caller to " << dest << ": " << freqCallers[x] << endl;
                for (int j = 0; j < subs[i]->getInCalls()->getNumCalls(); j++) {
                    if (subs[i]->getInCalls()->get(j)->getSrc() == freqCallers[x]) {
                        subs[i]->getInCalls()->get(j)->print();
                    }
                }
                cout << endl;
            }
            break;
        }
    }
}


void Telco::printFreqCallersAll(string freqCallers[], int num) {
    for (int i = 0; i < num; i++) {
        cout << "==> Most frequent caller to all: " << freqCallers[i] << endl;
        for (int j = 0; j < allCalls->getNumCalls(); j++) {
            if (allCalls->get(j)->getSrc() == freqCallers[i]) {
                allCalls->get(j)->print();
            }
        }
        cout << endl;
    }
}

void Telco::printFreqCalled(string freqCallers[], int num, string src) {
    for (int i = 0; i < numSubs; i++) {
        if (subs[i]->getPhoneNum() == src) {
            for (int x = 0; x < num; x++) {
                cout << "==> Most frequent called by " << src << ": " << freqCallers[x] << endl;
                for (int j = 0; j < subs[i]->getOutCalls()->getNumCalls(); j++) {
                    if (subs[i]->getOutCalls()->get(j)->getDest() == freqCallers[x]) {
                        subs[i]->getOutCalls()->get(j)->print();
                    }
                }
                cout << endl;
            }
            break;
        }
    }
}


void Telco::printFreqCalledAll(string freqCallers[], int num) {
    for (int i = 0; i < num; i++) {
        cout << "==> Most frequent called to all: " << freqCallers[i] << endl;
        for (int j = 0; j < allCalls->getNumCalls(); j++) {
            if (allCalls->get(j)->getDest() == freqCallers[i]) {
                allCalls->get(j)->print();
            }
        }
        cout << endl;
    }
}

void Telco::print() {
    cout << endl << endl << "TELCO " << name << endl << endl;
    for (int i = 0; i < numSubs; i++) {
        subs[i]->print();
    }
}
