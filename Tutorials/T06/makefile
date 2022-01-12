t6:	Animal.o CLient.o Control.o CriteriaArray.o Identifiable.o Match.o MatchList.o MatchListByScore.o MatchListByClient.o
	g++ -o t6 main.o Date.o Time.o Call.o Control.o Telco.o Subscriber.o Array.o View.o

main.o:	main.cc Control.h
	g++ -c main.cc

Animal.o:	Animal.cc Animal.h Identifiable.h
	g++ -c Animal.cc

Client.o: Client.cc Client.h Identifiable.h CriteriaArray.h
	g++ -c Client.cc

Control.o: Control.cc Control.h Client.h Animal.h MatchListByScore.h MatchListByClient.h
	g++ -c Control.cc

CriteriaArray.o: CriteriaArray.cc CriteriaArray.h defs.h Criteria.h
	g++ -c CriteriaArray.cc

Match.o: Match.cc Match.h Animal.h Client.h
	g++ -c View.cc

MatchList.o: Matchlist.cc MatchList.h Match.h
	g++ -c MatchList.cc

MatchListByClient.o: MatchListByClient.cc MatchListByClient.h MatchList.h
	g++ -c MatchListByClient.cc

MatchListByClient.o: MatchListByScore.cc MatchListByScore.h MatchList.h
	g++ -c MatchListByScore.cc

Criteria.o: Criteria.h Criteria.cc
	g++ -c Criteria.cc


clean:
	rm -f *.o t6
