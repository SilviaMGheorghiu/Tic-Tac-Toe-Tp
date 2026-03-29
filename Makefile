CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: joc

joc: main.o game.o
	$(CC) $(CFLAGS) main.o game.o -o joc

main.o: main.c game.h
	$(CC) $(CFLAGS) -c main.c

game.o: game.c game.h
	$(CC) $(CFLAGS) -c game.c

clean:
	rm -f *.o joc