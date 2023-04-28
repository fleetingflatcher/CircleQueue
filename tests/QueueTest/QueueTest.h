#ifndef FF_QUEUETEST_H
#define FF_QUEUETEST_H

#include "../CircleQueue.h"

class QueueTest {
public:
	QueueTest(int sz) : q(sz) {}
	void push(int item);
	void pop();
	void rotate(int item);
	int max();
	int sz();
	void printSz();
	void printMax();
	int get(int index);
	int front();
	int back();
	void print();

private:
	CircleQueue<int> q;
};

#endif // FF_QUEUETEST_H