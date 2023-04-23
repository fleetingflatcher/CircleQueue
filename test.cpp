#include "CircleQueue.h"
#include <iostream>

int main() {
    // Create a queue of integers with a maximum size of 5
    CircleQueue<int> queue(5);
    
    // Add some elements to the queue
    queue.push(1);
    queue.push(2);
    queue.push(3);
    
    // Print the front element of the queue
    std::cout << "Front element: " << queue.front() << std::endl;
    
    // Remove an element from the queue and print it
    int element = queue.pop();
    std::cout << "Popped element: " << element << std::endl;
    
    // Add another element to the queue
    queue.push(4);
    
    // Rotate the elements in the queue
    int rotated = queue.rotate(5);
    std::cout << "Rotated element: " << rotated << std::endl;
    
    // Print the contents of the queue
    std::cout << "Queue contents: ";
    for (int i = 0; i < queue.curr_sz; i++) {
        std::cout << queue[i] << " ";
    }
    std::cout << std::endl;
    
    // Print the maximum size of the queue
    std::cout << "Maximum queue size: " << queue.max_sz << std::endl;
    
    return 0;
}
