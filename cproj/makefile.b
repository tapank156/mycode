mfirst : object/mainApp.o object/first.o object/error.o 
	g++ -o object/mfirst object/mainApp.o object/first.o object/error.o

object/mainApp.o : mainApp.cc include/first.h include/error.h include/util.h 
	g++ -g -O2 -Wall mainApp.cc -o object/mainApp.o -c

object/error.o : implement/error.cc include/error.h include/util.h
	g++ -g -O2 -Wall implement/error.cc -o object/error.o -c

object/first.o : implement/first.cc include/first.h include/util.h
	g++ -g -O2 -Wall implement/first.cc -o object/first.o -c

clean : 
	rm object/mfirst object/*.o

