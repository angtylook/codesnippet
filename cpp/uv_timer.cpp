#include <iostream>
#include "uv.h"

int main()
{
    uv_loop_t *loop = uv_default_loop();
    uv_timer_t timer;
    uv_timer_init(loop, &timer);
    timer.data = (void*)1;
    uv_timer_start(&timer, [](uv_timer_t *handle) {
        std::cout << "timer time: " << int(handle->data) << std::endl;
        handle->data = (void*)(int(handle->data) + 1);
        if(int(handle->data) == 4) {
            uv_timer_stop(handle);
            uv_close((uv_handle_t*)handle, [](uv_handle_t *handle) {
                std::cout << "timer closed" << std::endl;
            });
        }
    }, 1000, 1000);

    uv_timer_t once;
    uv_timer_init(loop, &once);
    once.data = (void*)"two";
    uv_timer_start(&once, [](uv_timer_t *handle) {
        std::cout << "once" << (const char*)handle->data << std::endl;
    }, 1000, 0);

    uv_run(loop, UV_RUN_DEFAULT);
    return 0;
}