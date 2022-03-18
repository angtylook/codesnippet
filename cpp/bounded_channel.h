#ifndef BOUNDED_CHANNEL_H
#define BOUNDED_CHANNEL_H

#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <optional>

template<typename T>
class BoundedChannel {
public:
    BoundedChannel (size_t n): max_sz_(n), close_(false) {}

    bool Send(T v) {
        if(IsClose()) {
            return false;
        }

        std::unique_lock l(m_);
        cv_.wait(l, [this](){ return queue_.size() < max_sz_;});
        queue_.push(std::move(v));
        if(queue_.size() == 1) {
            cv_.notify_one();
        }
        return true;
    }

    std::optional<T> Recv() {
        if(IsClose() && Empty()) {
            return std::nullopt;
        }
        std::unique_lock l(m_);
        cv_.wait(l, [this](){ return !queue_.empty();});
        auto v = queue_.front();
        queue_.pop();
        if(queue_.empty() && !IsClose()) {
            cv_.notify_one();
        }
        return v;
    }

    bool Empty() {
        std::lock_guard l(m_);
        return queue_.empty();
    }

    void Close() {
        close_.store(true);
    }

    bool IsClose() {
        return close_.load();
    }

private:
    size_t max_sz_;
    std::queue<T> queue_;
    std::atomic<bool> close_;
    std::mutex m_;
    std::condition_variable cv_;
};

#endif

