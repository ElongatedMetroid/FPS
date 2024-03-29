CC=gcc
LIBS=-lraylib -lGL -lm -lpthread -ldl -lrt -lX11
CFLAGS=-g -Wall -Iinclude
OUTFILE=bin/fps.out
SRC=*.c src/*.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUTFILE) $(LIBS)

clean:
	rm $(OUTFILE)