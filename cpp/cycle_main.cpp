#include <iostream>
#include "cycle_thread.h"

class CycleExample {
public:
    CycleExample() {
        std::cout << "CycleExample::CycleExample()" << std::endl;
    }

    ~CycleExample() {
        std::cout << "CycleExample::~CycleExample()" << std::endl;
    }

    void Start() {
        thread_.SetStartCB(std::bind(&CycleExample::OnStart, this));
        thread_.SetStopCB(std::bind(&CycleExample::OnStop, this));
        thread_.Start(std::bind(&CycleExample::OnCycle, this), std::chrono::milliseconds(1000));
    }

    void Stop() {
        thread_.Stop();
    }

private:
    int OnCycle() {
        std::cout << "CycleExample::Cycle()" << std::endl;
        return 0;
    }

    bool OnStart() {
        std::cout << "CycleExample::OnStart()" << std::endl;
        return true;
    }

    void OnStop() {
        std::cout << "CycleExample::OnStop()" << std::endl;
    }

private:
    CycleThread thread_;
};


int main() {
    CycleExample example;
    example.Start();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    example.Stop();
    return 0;
}
