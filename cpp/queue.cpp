#include <iostream>

#include "bounded_channel.h"

int main() {
    BoundedChannel<int> q(10);
    for(int i = 0; i < 10; i++) {
        q.Send(i);
    }

    std::thread p([&q]{
        for(int i = 0; i < 10; i++) {
            int v;
            std::cin >> v;
            q.Send(v);
        }
        q.Close();
    });

    std::thread c([&q]{
        while (true)
        {
            auto v = q.Recv();
            if(v.has_value())
            {
                std::cout << "v=" << v.value() << std::endl;
            } else {
                std::cout << "no value done" << std::endl;
                break;
            }
        }
    });

    p.join();
    c.join();
    return 0;
}
