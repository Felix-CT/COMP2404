fp:	main.o ReportGenerator.o Control.o FarmDistributionReport.o Record.o View.o PercentageChangeReport.o HorseReport.o
	g++ -o fp main.o ReportGenerator.o Control.o FarmDistributionReport.o Record.o View.o PercentageChangeReport.o HorseReport.o

Control.o: Control.cc Control.h ReportGenerator.h View.h FarmDistributionReport.h PercentageChangeReport.h
	g++ -c Control.cc

ReportGenerator.o: ReportGenerator.cc ReportGenerator.h Map.h Record.h
	g++ -c ReportGenerator.cc

FarmDistributionReport.o: PercentageChangeReport.cc FarmDistributionReport.h ReportGenerator.h CompareBehaviour.h ReportData.h
	g++ -c FarmDistributionReport.cc

PercentageChangeReport.o: PercentageChangeReport.cc PercentageChangeReport.h ReportGenerator.h CompareBehaviour.h ReportData.h
	g++ -c PercentageChangeReport.cc

HorseReport.o: HorseReport.cc HorseReport.h ReportGenerator.h CompareBehaviour.h ReportData.h
	g++ -c HorseReport.cc

Record.o: Record.cc Record.h
	g++ -c Record.cc

View.o: View.cc View.h
	g++ -c View.cc

clean:
	rm -f *.o fp
