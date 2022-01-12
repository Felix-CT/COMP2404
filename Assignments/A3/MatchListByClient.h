/*
  This class is a derived class of MatchList, and it sorts the matches by
  client, and then by score.
*/

#ifndef MATCHLISTBYCLIENT_H
#define MATCHLISTBYCLIENT_H

#include "MatchList.h"

class MatchListByClient : public MatchList
{
  public:
    void add(Match*);
};

#endif
