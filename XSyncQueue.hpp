#include <mutex>
#include <thread>
#include <condition_variable>
#include <iostream>
#include <list>
/*
同步队列实现
*/
template <typename T>

class XSyncQueue
{
private:
    std::list<T> m_queue;
    std::mutex m_mutex;
    std::condition_variable m_notEmpty;

public:
    XSyncQueue(){}

    void Put(const T& x)
    {
        std::lock_guard<std::mutex> locker(m_mutex);
        m_queue.push_back(x);
        m_notEmpty.notify_one();
    }

    void Take(T& x)
    {
        std::unique_lock<std::mutex> locker(m_mutex);
        m_notEmpty.wait(locker,[this]{return !m_queue.empty();});
        x = m_queue.front();
        m_queue.pop_front();
    }

    bool Empty()
    {
        std::lock_guard<std::mutex> locker(m_mutex);
        return m_queue.empty();
    }

    size_t Size()
    {
        std::lock_guard<std::mutex> locker(m_mutex);
        return m_queue.size();
    }

};