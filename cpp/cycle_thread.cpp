#include <chrono>
#include "cycle_thread.h"

CycleThread::CycleThread()
{
}

CycleThread::~CycleThread()
{
}

bool CycleThread::Start(std::function<int()> func, std::chrono::milliseconds interval)
{
    if(!func) {
        return false;
    }

    on_cycle_ = func;
    interval_ = interval;
    thread_ = std::jthread(std::bind_front(&CycleThread::Run, this));
    if(ready_promise_.get_future().wait_for(std::chrono::seconds(3)) == std::future_status::timeout) {
        return false;
    }
    return true;
}

void CycleThread::Run(std::stop_token token)
{
    if(on_start_) {
        if(!on_start_()) {
            return;
        }
    }

    ready_promise_.set_value(true);

    while(!token.stop_requested()) {
        if(on_cycle_) {
            int ret = on_cycle_();
            if(ret != 0) {
                break;
            }
        }
        std::this_thread::sleep_for(interval_);
    }

    if(on_stop_) {
        on_stop_();
    }
}

void CycleThread::Stop()
{
    if(thread_.joinable()) {
        thread_.request_stop();
        thread_.join();
    }
}

void CycleThread::SetStartCB(std::function<bool()> func)
{
    on_start_ = func;
}

void CycleThread::SetStopCB(std::function<void()> func)
{
    on_stop_ = func;
}

