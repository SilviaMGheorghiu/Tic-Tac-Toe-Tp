CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: joc

joc: main.o game.o ai.o ai2.o ai3.o powerUp.o
	$(CC) $(CFLAGS) main.o game.o ai.o ai2.o ai3.o powerUp.o -o joc

main.o: main.c game.h ai.h ai2.h ai3.h powerUp.h
	$(CC) $(CFLAGS) -c main.c

game.o: game.c game.h ai.h ai2.h ai3.h powerUp.h
	$(CC) $(CFLAGS) -c game.c

ai.o: ai.c ai.h game.h
	$(CC) $(CFLAGS) -c ai.c

ai2.o: ai2.c ai2.h game.h
	$(CC) $(CFLAGS) -c ai2.c

ai3.o: ai3.c ai3.h game.h
	$(CC) $(CFLAGS) -c ai3.c

powerUp.o: powerUp.c powerUp.h game.h
	$(CC) $(CFLAGS) -c powerUp.c

clean:
	rm -f *.o joc