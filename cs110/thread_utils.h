#ifndef THREAD_UTILS_H_
#define THREAD_UTILS_H_

#include <thread>
#include <chrono>

void sleep_for(const unsigned t) {
    const std::chrono::milliseconds s(t);
    std::this_thread::sleep_for(s);
}

#endif