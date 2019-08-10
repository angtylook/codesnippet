#include <iostream>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>

using namespace std::placeholders;

class Application {
    public:
    Application(){}

    void loadData() {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "loading data from XML" << std::endl;
        std::lock_guard guard(mutex_);
        loaded_ = true;
        cv_.notify_one();
    }

    bool isLoaded() {
        return loaded_;
    }

    void mainTask() {
        std::cout << "do some handshaking" << std::endl;
        std::unique_lock lock(mutex_);
        cv_.wait(lock, std::bind(&Application::isLoaded, this));
        std::cout << "do processing on loaded data" << std::endl;
    }
    private:
    std::mutex mutex_;
    std::condition_variable cv_;
    bool loaded_ {false};
};

int main() {
    Application app;
    std::thread thread_1(&Application::mainTask, &app);
    std::thread thread_2(&Application::loadData, &app);
    thread_2.join();
    thread_1.join();
    return 0;
}