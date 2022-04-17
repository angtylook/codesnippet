#include <iostream>
#include <thread>
#include "uv.h"

int main()
{
    uv_loop_t *loop = uv_default_loop();
    int data = 0;
    uv_work_t work;
    work.data = &data;
    uv_queue_work(loop, &work, [](uv_work_t *req) {
        std::cout << "work in " << std::this_thread::get_id() << std::endl;
        req->data = (void*)(int(req->data) + 1);
    }, [](uv_work_t *req, int status) {
        std::cout << "work done " << (int)req->data << "in " << std::this_thread::get_id() << std::endl;
    });

    uv_run(loop, UV_RUN_DEFAULT);
    return 0;
}