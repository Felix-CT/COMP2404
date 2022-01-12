a2:	main.o Date.o Time.o Call.o Control.o Telco.o Subscriber.o Array.o View.o
	g++ -o a2 main.o Date.o Time.o Call.o Control.o Telco.o Subscriber.o Array.o View.o

main.o:	main.cc Control.h
	g++ -c main.cc

Date.o:	Date.cc Date.h
	g++ -c Date.cc

Control.o: Control.cc Control.h Call.h
	g++ -c Control.cc

Time.o: Time.cc Time.h
	g++ -c Time.cc

Call.o: Call.cc Call.h Date.h Time.h
	g++ -c Call.cc

View.o: View.cc View.h
	g++ -c View.cc

Telco.o: Telco.cc Telco.h Subscriber.h Array.h Call.h
	g++ -c Telco.cc

Subscriber.o: Subscriber.cc Subscriber.h Call.h Array.h
	g++ -c Subscriber.cc

Array.o: Array.cc Array.h Call.h
	g++ -c Array.cc

clean:
	rm -f *.o a2
