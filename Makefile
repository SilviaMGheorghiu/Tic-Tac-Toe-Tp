CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: joc

joc: main.o game.o ai.o
	$(CC) $(CFLAGS) main.o game.o ai.o -o joc

main.o: main.c game.h ai.h
	$(CC) $(CFLAGS) -c main.c

game.o: game.c game.h
	$(CC) $(CFLAGS) -c game.c

ai.o: ai.c ai.h game.h
	$(CC) $(CFLAGS) -c ai.c

clean:
	rm -f *.o joc