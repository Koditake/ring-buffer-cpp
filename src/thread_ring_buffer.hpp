#pragma once

#include <vector>
#include <mutex>
#include <condition_variable>
#include <cstddef>

template <typename T>

class RingBufferLock
{
    public:
        RingBufferLock(std::size_t capacity);

        bool Enqueue(const T &element);

        bool Dequeue(const T &element);

        bool full() const;
        
        bool empty() const;

        std::size_t size();
    private:
        std::vector<T> buffer;
        std::size_t head;
        std::size_t tail;
        std::size_t capacity;
        std::mutex mutex;
        std::condition_variable full_cond;
        std::condition_variable empty_cond;

        bool updateHead(const T &element);

        bool updateTail(T &element);
};