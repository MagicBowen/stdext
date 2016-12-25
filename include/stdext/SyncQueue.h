#ifndef HADEAEE88_CA9D_4D7A_BF49_160D288028D7
#define HADEAEE88_CA9D_4D7A_BF49_160D288028D7

#include <stdext/Synchronization.h>
#include <condition_variable>
#include <deque>

STDEXT_NS_BEGIN

template<typename T>
struct SyncQueue
{
    SyncQueue() = default;
    SyncQueue(const SyncQueue&) = delete;
    SyncQueue& operator=(const SyncQueue&) = delete;

    void put(const T& t)
    {
        SYNCHRONIZED(mutex)
        {
            queue.push_back(t);
        }
        notEmpty.notify_one();
    }

    void put(T&& t)
    {
        SYNCHRONIZED(mutex)
        {
            queue.push_back(std::move(t));
        }
        notEmpty.notify_one();
    }

    T take()
    {
        std::unique_lock<std::mutex> lock(mutex);

        while(true)
        {
            notEmpty.wait(lock, [this]{return !queue.empty();});
            if(!queue.empty()) break;
        }

        T front(std::move(queue.front()));
        queue.pop_front();
        return front;
    }

    size_t size() const
    {
        std::unique_lock<std::mutex> lock(mutex);
        return queue.size();
    }

private:
    mutable std::mutex mutex;
    std::condition_variable notEmpty;
    std::deque<T> queue;
};

STDEXT_NS_END

#endif
