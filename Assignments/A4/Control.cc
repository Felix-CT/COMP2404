#include <iostream>
using namespace std;
#include <string>
#include "Control.h"

Control::Control(){
  resMgr = new ResManager(NULL);
  hotel = new Hotel("Felix's hotel", resMgr);
  resMgr->setHotel(hotel);

  view = View();

  StayRecorder* sRecorder = new StayRecorder("Stay");
  GuestRecorder* gRecorder = new GuestRecorder("Guest");
  UpgradeRecorder* uRecorder = new UpgradeRecorder("Upgrade");
  resMgr->subscribe(gRecorder);
  resMgr->subscribe(sRecorder);
  resMgr->subscribe(uRecorder);
}

Control::~Control(){
  delete resMgr;
  delete hotel;
}

void Control::launch(){
  initHotel();
  bool run = true;
  int response;

  while (run){
    view.showMenu(response);
    switch (response){
      case 1:
        resMgr->print();
        break;
      case 2:
        hotel->printRooms();
        break;
      case 3:
        hotel->printGuests();
        break;
      case 4:
        resMgr->printRecords();
        break;
      case 0:
        run = false;
        break;
      default:
        cout << "You have not entered a valid selection, please try again.";
        break;
    }
  }
}

void Control::initHotel()
{
  hotel->addGuest(new Guest("Juliet", true));
  hotel->addGuest(new Guest("Ben", true));
  hotel->addGuest(new Guest("Goodwin"));
  hotel->addGuest(new Guest("Harper", true));
  hotel->addGuest(new Guest("Ethan"));
  hotel->addGuest(new Guest("Horace"));
  hotel->addGuest(new Guest("Aimee"));

  hotel->addRoom(new Room(C_SUITE, 501, 1500));
  hotel->addRoom(new Room(C_PREM, 410, 700));
  hotel->addRoom(new Room(C_PREM, 420, 700));
  hotel->addRoom(new Room(C_REG, 322, 300));
  hotel->addRoom(new Room(C_REG, 324, 300));
  hotel->addRoom(new Room(C_REG, 326, 300));
  hotel->addRoom(new Room(C_REG, 212, 200));
  hotel->addRoom(new Room(C_REG, 214, 200));
  hotel->addRoom(new Room(C_REG, 216, 200));
  hotel->addRoom(new Room(C_REG, 218, 200));

  resMgr->addReservation("Ben",     2021, 5, 11,  4, C_PREM);
  resMgr->addReservation("Juliet",  2021, 5, 10,  3, C_PREM);
  resMgr->addReservation("Horace",  2021, 5, 28, 10, C_PREM);
  resMgr->addReservation("Aimee",   2021, 5, 28,  8, C_PREM);
  resMgr->addReservation("Sophie",  2021, 5, 28,  8, C_PREM);
  resMgr->addReservation("Harper",  2021, 5, 12,  1, C_PREM);
  resMgr->addReservation("Harper",  2021, 5, 12,  1, C_REG);
  resMgr->addReservation("Ethan",   2021, 5,  8,  7, C_REG);
  resMgr->addReservation("Ethan",   2021, 5, 28, 10, C_REG);
  resMgr->addReservation("Timmy",   2021, 5, 28,  8, C_REG);
  resMgr->addReservation("Horace",  2021, 5, 25,  2, C_REG);
  resMgr->addReservation("Goodwin", 2021, 5, 25, 12, C_REG);
  resMgr->addReservation("Ben",     2021, 5, 27,  5, C_REG);
  resMgr->addReservation("Harper",  2021, 5, 29,  2, C_SUITE);
  resMgr->addReservation("Juliet",  2021, 5, 30,  1, C_SUITE);

}
