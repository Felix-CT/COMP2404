a3:	main.o Animal.o Shelter.o View.o Client.o Control.o Criteria.o CriteriaArray.o Identifiable.o Match.o MatchList.o MatchListByScore.o MatchListByClient.o
	g++ -o a3 main.o Shelter.o View.o Animal.o Client.o Control.o Criteria.o CriteriaArray.o Identifiable.o Match.o MatchList.o MatchListByScore.o MatchListByClient.o

Animal.o:	Animal.cc Animal.h Identifiable.h defs.h
	g++ -c Animal.cc

Client.o: Client.cc Client.h Identifiable.h CriteriaArray.h
	g++ -c Client.cc

Control.o: Control.cc Control.h Animal.cc Client.cc Shelter.h MatchListByScore.h MatchListByClient.h Criteria.h
	g++ -c Control.cc

CriteriaArray.o: CriteriaArray.cc CriteriaArray.h defs.h Criteria.h
	g++ -c CriteriaArray.cc

Match.o: Match.cc Match.h Animal.h Client.h
	g++ -c Match.cc

MatchList.o: MatchList.cc MatchList.h Match.h
	g++ -c MatchList.cc

Identifiable.o: Identifiable.cc Identifiable.h
	g++ -c Identifiable.cc

MatchListByClient.o: MatchListByClient.cc MatchListByClient.h MatchList.h
	g++ -c MatchListByClient.cc

MatchListByScore.o: MatchListByScore.cc MatchListByScore.h MatchList.h
	g++ -c MatchListByScore.cc

Criteria.o: Criteria.h Criteria.cc
	g++ -c Criteria.cc

Shelter.o: Shelter.cc Shelter.h Animal.h Client.h MatchListByScore.h MatchListByClient.h defs.h
	g++ -c Shelter.cc

View.o: View.cc View.h
	g++ -c View.cc

main.o:	main.cc Control.h
	g++ -c main.cc


clean:
	rm -f *.o a3
