#include "ring_buffer.hpp"

template <typename T>
// Constructor with capacity
RingBuffer<T>::RingBuffer(std::size_t capacity) : buffer(capacity), head(0), tail(0)
{
}

template <typename T>
// Enqueue element
bool RingBuffer<T>::Enqueue(const T &element)
{
    if (this->full()) 
    {
        return false;
    }
    buffer[head] = element;
    head = (head + 1) % capacity;
    return true;
}

template <typename T>
// Dequeue element
bool RingBuffer<T>::Dequeue(const T &element)
{
    if (this->empty())
    {
        return false;
    }
    element = buffer[tail];
    tail = (tail + 1) % capacity;
    return true;
}

template <typename T>
// Check if buffer is full
bool RingBuffer<T>::full() const
{
    return (head + 1) % capacity == tail;
}

template <typename T>
// Check if buffer is empty
bool RingBuffer<T>::empty() const
{
    return head == tail;
}

template <typename T>
// Get the size of the buffer
std::size_t RingBuffer<T>::size() const
{
    if (head >= tail) {
        return head - tail;
    }

    return capacity + head - tail;
}
