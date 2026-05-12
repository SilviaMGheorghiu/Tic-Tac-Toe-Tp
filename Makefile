CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: joc

joc: main.o game.o ai.o ai2.o
	$(CC) $(CFLAGS) main.o game.o ai.o ai2.o -o joc

main.o: main.c game.h ai.h ai2.h
	$(CC) $(CFLAGS) -c main.c

game.o: game.c game.h ai.h ai2.h
	$(CC) $(CFLAGS) -c game.c

ai.o: ai.c ai.h game.h
	$(CC) $(CFLAGS) -c ai.c

ai2.o: ai2.c ai2.h game.h
	$(CC) $(CFLAGS) -c ai2.c

clean:
	rm -f *.o joc