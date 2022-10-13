OBJS = main.o segment.o racer.o race.o 
EXE = run
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

$(EXE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(EXE)

Ashour_Ash_main.o: segment.h racer.h race.h
	$(CC) $(CFLAGS) main.cpp

Ashour_Segment.o: segment.h
	$(CC) $(CFLAGS) segment.cpp
Ashour_Racer.o: racer.h
	$(CC) $(CFLAGS) racer.cpp
Ashour_Race.o: race.h segment.h racer.h
	$(CC) $(CFLAGS) race.cpp
clean:
	rm *.o $(EXE) *~ -v