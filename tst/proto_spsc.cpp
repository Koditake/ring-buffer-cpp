#include "../src/ring_buffer.hpp"

#include <iostream>

int main (int argc, char *argv[])
{
    // Create a ring buffer with capacity 5
    RingBuffer<int> buffer(5);

    // Enqueue elements
    buffer.Enqueue(1);
    buffer.Enqueue(2);
    buffer.Enqueue(3);

    // Check size of the buffer
    std::cout << "Buffer size: " << buffer.size() << std::endl;

    // Dequeue element
    int element;
    buffer.Dequeue(element);

    // Print dequeued element
    std::cout << "Dequeued element: " << element << std::endl;

    return 0;
}