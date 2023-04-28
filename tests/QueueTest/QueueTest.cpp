#include <iostream>
#include "QueueTest.h"

void QueueTest::push(int item) {
	q.push(item);
	std::cout << "Pushed " << item << " to queue." << std::endl;
}

void QueueTest::pop() {
	int item = q.pop();
	std::cout << "Popped " << item << " from queue." << std::endl;
}

void QueueTest::rotate(int item) {
	int catcher;
    if (q.rotate(item, catcher))
    	std::cout << "Rotated " << item << " to the back of the queue, caught " << catcher << "." << std::endl;
    else
		std::cout << "Rotated " << item << " to the back of the queue." << std::endl;
}

void QueueTest::printMax() { std::cout << "The maximum element in the queue is " << q.max_sz << "." << std::endl; }

int QueueTest::max() { return q.max_sz; }

void QueueTest::printSz() { std::cout << "The current size of the queue is " << q.curr_sz << "." << std::endl; }

int QueueTest::sz() { return q.curr_sz; }

int QueueTest::get(int index) {
    try {
        return q[index];
    }
    catch (cq_null_reference& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
        return -1; // Or any other value to indicate error
    }
}

int QueueTest::front() {
    try {
        return q.front();
    }
    catch (cq_null_reference& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
        return -1; // Or any other value to indicate error
    }
}

int QueueTest::back() {
    try {
        return q.back();
    }
    catch (cq_null_reference& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
        return -1; // Or any other value to indicate error
    }
}

void QueueTest::print() {
	std::cout << "Queue contents: ";
    for (int i = 0; i < q.curr_sz; i++) {
        std::cout << q[i] << " ";
    }
    std::cout << std::endl;
}
