/*
  The purpose of this class is to act as the base class of the MatchListByScore
  and the MatchListByClient classes, which provides useful member functions as
  well as using a linked list data structure to store the classes.
*/
#ifndef MATCHLIST_H
#define MATCHLIST_H

#include "Match.h"

class MatchList
{


  public:
    MatchList();
    ~MatchList();
    void cleanup();
    void print() const;

  protected:

    class Node
    {
    public:
        Match* data;
        Node* next;
    };

    Node* head;
};

#endif
