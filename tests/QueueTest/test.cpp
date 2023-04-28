#include "QueueTest.h"
#include <iostream>

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
