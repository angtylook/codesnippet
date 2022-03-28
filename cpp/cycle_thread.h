#ifndef CYCLE_THREAD_H
#define CYCLE_THREAD_H

#include <thread>
#include <functional>
#include <future>
#include <chrono>

class CycleThread {
public:
    CycleThread();
    ~CycleThread();
public:
    bool Start(std::function<int()> func, std::chrono::milliseconds interval = std::chrono::milliseconds(10));
    void Run(std::stop_token token);
    void Stop();

    void SetStartCB(std::function<bool()> func);
    void SetStopCB(std::function<void()> func);
private:
    std::jthread thread_;
    std::function<int()> on_cycle_;
    std::function<bool()> on_start_;
    std::function<void()> on_stop_;
    std::promise<bool> ready_promise_;
    std::chrono::milliseconds interval_;
};

#endif
