a4:	main.o  Room.o Guest.o Hotel.o Control.o ResManager.o RoomArray.o GuestRecorder.o Recorder.o Reservation.o StayRecorder.o UpgradeRecorder.o Date.o View.o
	g++ -o a4 main.o Room.o Guest.o Hotel.o Control.o ResManager.o RoomArray.o GuestRecorder.o Recorder.o Reservation.o StayRecorder.o UpgradeRecorder.o Date.o View.o

Room.o:	Room.cc Room.h defs.h
	g++ -c Room.cc

Guest.o: Guest.cc Guest.h
	g++ -c Guest.cc

Control.o: Control.cc Control.h ResManager.h Hotel.h StayRecorder.h GuestRecorder.h UpgradeRecorder.h View.h

Hotel.o: Hotel.cc Hotel.h defs.h Guest.h RoomArray.h ResManager.h
	g++ -c Hotel.cc

ResManager.o: ResManager.cc ResManager.h Hotel.h defs.h Recorder.h
	g++ -c ResManager.cc

RoomArray.o: RoomArray.cc RoomArray.h defs.h Room.h
	g++ -c RoomArray.cc

main.o:	main.cc Control.h
	g++ -c main.cc

GuestRecorder.o: GuestRecorder.cc GuestRecorder.h Recorder.h
	g++ -c GuestRecorder.cc

Recorder.o: Recorder.cc Recorder.h Reservation.h
	g++ -c Recorder.cc

Reservation.o: Reservation.cc Reservation.h Guest.h Room.h Date.h
	g++ -c Reservation.cc

StayRecorder.o: StayRecorder.cc StayRecorder.h Recorder.h
	g++ -c StayRecorder.cc

UpgradeRecorder.o: UpgradeRecorder.cc UpgradeRecorder.h Recorder.h Reservation.h
	g++ -c UpgradeRecorder.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc

View.o: View.cc View.h
	g++ -c View.cc

clean:
	rm -f *.o a4
