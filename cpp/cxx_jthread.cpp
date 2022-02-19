#include <functional>
#include <iostream>
#include <queue>
#include <syncstream>
#include <thread>

void do_task(int param) {
    std::osyncstream(std::cout)
        << "doing task with " << param
        << " from thread: " << std::this_thread::get_id() << std::endl;
}

class TaskRunner {
public:
    TaskRunner():thread_{&TaskRunner::run}{};

    void post(std::function<void()> task) { tasks_.push(std::move(task)); }

private:
    void run(std::stop_token token) {
        while (true) {
            std::queue<std::function<void()>> tasks;
            std::swap(tasks, tasks_);
            run_task(tasks);
            if (token.stop_requested()) {
                std::queue<std::function<void()>> tasks;
                std::swap(tasks, tasks_);
                run_task(tasks);
                return;
            }
        }
    }

    void run_task(std::queue<std::function<void()>> tasks) {
        while (!tasks.empty()) {
            auto& task = tasks.front();
            task();
            tasks.pop();
        }
    }

private:
    std::jthread thread_;
    std::queue<std::function<void()>> tasks_;
};

int main() {
    std::jthread t1{do_task, 1};
    std::jthread t2{do_task, 2};
    t2.detach();
    return 0;
}
