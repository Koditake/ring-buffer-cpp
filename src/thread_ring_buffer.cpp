#include "thread_ring_buffer.hpp"

template <typename T>
RingBufferLock<T>::RingBufferLock(std::size_t capacity) : buffer(capacity), head(0), tail(0), mutex(), full_cond(), empty_cond() {}

template <typename T>
bool RingBufferLock<T>::Enqueue(const T &element)
{
    std::unique_lock<std::mutex> lock(mutex);
    while (full()) {
        full_cond.wait(lock);
    }

    return updateHead(&element);
}

template <typename T>
bool RingBufferLock<T>::Dequeue(const T &element)
{
    std::unique_lock<std::mutex> lock(mutex);
    while (empty()) {
        empty_cond.wait(lock);
    }
    return updateTail(&element);
}

template <typename T>
bool RingBufferLock<T>::full() const
{
    return (head + 1) % capacity == tail;
}

template <typename T>
bool RingBufferLock<T>::empty() const
{
    return head == tail;
}

template <typename T>
std::size_t size()
{
    if (head >= tail) {
        return head - tail;
    }

    return capacity + head - tail;
}

template <typename T>
bool RingBufferLock<T>::updateHead(const T &element) 
{
    buffer[head] = element;
    head = (head + 1) % capacity;
    empty_cond.notify_one();
    return true;
}

template <typename T>
bool RingBufferLock<T>::updateTail (T &element) 
{
    element = buffer[tail];
    tail = (tail + 1) % capacity;
    full_cond.notify_one();
    return true;
}
