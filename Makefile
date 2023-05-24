CC = gcc
CFLAGS = -Wall -std=c11 -g

all: main.o API.o run

clean:
	rm *.o run

run: API.o main.o 
	$(CC) $(CFLAGS) API.o main.o -o run 

API.o: API.h API.c
	$(CC) $(CFLAGS) -c API.c -o API.o 

main.o: main.c API.h
	$(CC) $(CFLAGS) -c main.c -o main.o

