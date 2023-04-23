#include "CircleQueue.h"
#include <iostream>

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

int main() {
    // Create a queue of integers with a maximum size of 5
    QueueTest queue(5);
    
    // Add some elements to the queue

    queue.push(1);
    queue.push(2);
    queue.push(3);
	
    
    // Print the front element of the queue
    queue.front();
    
    // Remove an element from the queue and print it
	queue.pop();
    queue.print();
    // Add another element to the queue
    queue.push(4);
	queue.print();
	queue.push(5);
	queue.print();

    
    // Rotate the elements in the queue
    queue.rotate(5);
	queue.rotate(4);
	queue.rotate(3);
	queue.rotate(2);
	queue.rotate(1);
    // Print the contents of the queue
    queue.print();
    queue.max();
    
    return 0;
}
