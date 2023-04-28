CC=g++
CFLAGS=-Wall -Wextra -Werror -pedantic -std=c++11

all: test

test: test.o
	$(CC) $(CFLAGS) test.o queueTest.o -o test

test.o: test.cpp queueTest.o
	$(CC) $(CFLAGS) -c test.cpp

queueTest.o: QueueTest.h QueueTest.cpp ../CircleQueue.h
	$(CC) $(CFLAGS) -c QueueTest.cpp -o queueTest.o

clean:
	rm -f *.o test