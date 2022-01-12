/*
  This class is a derived class of MatchList, and it sorts the matches by score.
*/
#ifndef MATCHLISTBYSCORE_H
#define MATCHLISTBYSCORE_H

#include "MatchList.h"

class MatchListByScore : public MatchList
{
  public:
    void add(Match*);
};

#endif
