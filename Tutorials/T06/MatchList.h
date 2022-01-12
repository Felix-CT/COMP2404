#ifndef MATCHLIST_H
#define MATCHLIST_H

#include "Match.h"

class MatchList
{
  protected class Node
  {
    public:
      Match* data;
      Node* next;
  };

  public:
    List();
    ~List();
    //void add(Student*);
    void cleanup();
    void print() const;

  protected:
    Node* head;

};

#endif
