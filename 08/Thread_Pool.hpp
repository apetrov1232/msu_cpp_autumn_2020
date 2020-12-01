#pragma once
#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <chrono>
#include <queue>
#include <string>
#include <ctime>


class ThreadPool{

    std::queue <void*> Queue;
    std::condition_variable next;
    bool work = true;
    std::mutex m;
    size_t Size = 0;
    size_t poolSize;

    void process(size_t i);

public:

    ThreadPool(size_t poolSize = std::thread::hardware_concurrency()){
        this->poolSize = poolSize;
        for (size_t i(0); i < poolSize; i++){
            std::thread t(&ThreadPool::process, this, i);
            t.detach();
        }
    }

    ~ThreadPool(){
        //try to end all threads before ~ThreadPool() finished
        this->m.lock();
        this->work = false;
        this->m.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(3));
        this->next.notify_all();
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    //it is some incorrect for ThreadPool to use copy/move constructor or operator=
    ThreadPool(const ThreadPool& other){
        for (size_t i(0); i < other.poolSize; i++){
            std::thread t(&ThreadPool::process, this, i);
            t.detach();
        }
    };
    ThreadPool(ThreadPool&& other) noexcept{
        for (size_t i(0); i < other.poolSize; i++){
            std::thread t(&ThreadPool::process, this, i);
            t.detach();
        }
    };
    ThreadPool& operator=(const ThreadPool& other){
        for (size_t i(0); i < other.poolSize; i++){
            std::thread t(&ThreadPool::process, this, i);
            t.detach();
        }
        return (*this);
    };
    ThreadPool& operator=(ThreadPool&& other) noexcept{
        for (size_t i(0); i < other.poolSize; i++){
            std::thread t(&ThreadPool::process, this, i);
            t.detach();
        }
        return (*this);
    };

    template <class Func, class... Args>
    auto exec(Func func, Args... args) -> std::future<decltype(func(args...))>;
};


#include "Thread_Pool.tpp"
