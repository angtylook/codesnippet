#include <iostream>
#include <chrono>

#include "bounded_channel.h"

using namespace std::chrono_literals;

int main() {
    BoundedChannel<int> q(10);

    std::thread p([&q]{
        for(int i = 0; i < 50; i++) {
            int v = i;
            // std::cin >> v;
            q.Send(v);
            std::cout << "push->" << v << std::endl;
            std::this_thread::sleep_for(100ms);
        }
        q.Close();
    });

    std::thread c([&q]{
        while (true)
        {
            auto v = q.Recv();
            if(v.has_value())
            {
                std::cout << "pop v=" << v.value() << std::endl;
            } else {
                std::cout << "no value done" << std::endl;
                break;
            }
            std::this_thread::sleep_for(200ms);
        }
    });

    p.join();
    c.join();
    return 0;
}
