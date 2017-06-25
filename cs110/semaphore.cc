#include "semaphore.h"

semaphore::semaphore(int value)
: value(value) {
}

void semaphore::wait() {
    std::lock_guard<std::mutex> lg(m);
    cv.wait(m, [this] { return value > 0; });
    value--;
}

void semaphore::signal() {
    std::lock_guard<std::mutex> lg(m);
    value++;
    if(value == 1)
        cv.notify_all();
}
