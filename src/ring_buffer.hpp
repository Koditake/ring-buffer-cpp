#pragma once

#include <vector>

template <typename T>

class RingBuffer 
{
    public:
        // Constructor with capacity
        RingBuffer(std::size_t capacity);
        // Enqueue element
        bool Enqueue(const T &element);
        // Dequeue element
        bool Dequeue(const T &element);
        // Check if buffer is full
        bool full() const;
        // Check if buffer is empty
        bool empty() const;
        // Get the size of the buffer
        std::size_t size() const;
    private:
        std::size_t capacity;
        std::size_t head;
        std::size_t tail;
        std::vector<T> buffer;
};