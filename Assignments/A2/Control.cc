#include <iostream>
using namespace std;
#include <string>

#include "Control.h"


Control::Control(string name){
  telco = new Telco(name);
  view = new View();
}

Control::~Control(){
  delete telco;
  delete view;
}

void Control::launch(){
  initData(telco);
  bool quit = false;
  int choice = 0;


  while (!quit){
    view->showMenu(choice);

    switch (choice) {
      case 0 :{
        quit = true;
        break;
      }
      case 1 :{
        string dest1;
        cout << "Enter destination subscriber, or all: ";
        view->readStr(dest1);
        cout << endl;
        telco->computeFreqCaller(dest1);
        break;
      }
      case 2 :{
        string src1;
        cout << "Enter destination subscriber, or all: ";
        view->readStr(src1);
        cout << endl;
        telco->computeFreqCalled(src1);
        break;
      }
      case 3 :{
        telco->print();
        break;
      }
      default: {
          cout << "You did not enter a valid entry.\n";
      }
    }
  }
}


void Control::initData(Telco* tel)
{
  initSubscribers(tel);
  initCalls(tel);
}

void Control::initSubscribers(Telco* tel)
{
  tel->addSub(new Subscriber("6139990000"));
  tel->addSub(new Subscriber("6133334444"));
  tel->addSub(new Subscriber("6138889999"));
  tel->addSub(new Subscriber("6131112222"));
  tel->addSub(new Subscriber("6132223333"));
  tel->addSub(new Subscriber("6134445555"));
}

void Control::initCalls(Telco* tel)
{
  tel->addCall("6139990000", "6133334444", 2020, 1, 1, 0, 31, 12);
  tel->addCall("6139990000", "6132223333", 2019, 2, 2, 10, 54, 2);

  tel->addCall("6132223333", "6139990000", 2019, 2, 23, 6, 33, 11);
  tel->addCall("6132223333", "6139990000", 2019, 3, 2, 10, 54, 2);
  tel->addCall("6132223333", "6139990000", 2019, 2, 20, 14, 22, 5);
  tel->addCall("6132223333", "6131112222", 2019, 12, 18, 4, 5, 15);

  tel->addCall("6131112222", "6132223333", 2019, 6, 30, 6, 2, 5);
  tel->addCall("6131112222", "6139990000", 2019, 8, 9, 8, 29, 7);
  tel->addCall("6131112222", "6130000000", 2019, 8, 9, 8, 29, 7);
  tel->addCall("6131112222", "6138889999", 2019, 3, 10, 15, 12, 11);

  tel->addCall("6134445555", "6138889999", 2019, 3, 10, 15, 22, 1);
  tel->addCall("6134445555", "6138887777", 2019, 3, 10, 15, 24, 10);
}
