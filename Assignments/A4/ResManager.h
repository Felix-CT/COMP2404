/*
  The purpose of this class is to manage all of the reservations in the hotel,
  and be able to manage all of the recorders which keep track of information
  about the reservations.
*/
#ifndef RESMANAGER_H
#define RESMANAGER_H
#include "string.h"
#include "Hotel.h"
#include "defs.h"
#include "Reservation.h"
#include "Recorder.h"
#include <vector>

class Hotel;

class ResManager
{
  public:
    ResManager(Hotel*);
    ~ResManager();
    void setHotel(Hotel*);
    void addReservation(string, int, int, int, int, ReqRoomType);
    void subscribe(Recorder*);
    void notify(Reservation*);
    void print();
    void printRecords();

  private:
    Hotel* hotel;
    Reservation** reservations;
    int numReservations;
    vector<Recorder*> recorders;
    bool checkConflictingDates(Date*, int, int);
    void addResHelper(Reservation*);
};

#endif
