CC=g++
CFLAGS=-Wall -Wextra -Werror -pedantic -std=c++11

all: test

test: test.o
	$(CC) $(CFLAGS) test.o -o test

test.o: test.cpp CircleQueue.h
	$(CC) $(CFLAGS) -c test.cpp

clean:
	rm -f $(OBJS) test