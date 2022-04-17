#include <iostream>

#include "uv.h"

void net_interface() {
    uv_interface_address_t* info;
    int count = 0;
    uv_interface_addresses(&info, &count);
    char buf[128] = {0};
    for (int i = 0; i < count; i++) {
        uv_interface_address_t* address = &info[i];
        std::cout << "name: " << address->name << std::endl;
        std::cout << "is_internal: " << address->is_internal << std::endl;
        if(address->address.address4.sin_family == AF_INET) {
            uv_ip4_name(&(address->address.address4), buf, sizeof(buf));
            std::cout << "ipv4: " << buf << std::endl;
        } else if(address->address.address4.sin_family == AF_INET6) {
            uv_ip6_name(&(address->address.address6), buf, sizeof(buf));
            std::cout << "ipv6: " << buf << std::endl;
        }
        std::cout << "==========================" << std::endl;
    }
    uv_free_interface_addresses(info, count);
}

int main()
{
    uv_loop_t* loop = uv_default_loop();

    uv_idle_t idle1;
    idle1.data = (void*)1;
    uv_idle_init(loop, &idle1);
    uv_idle_start(&idle1, [](uv_idle_t* handle) {
        std::cout << "idle1 in " << (int)handle->data << std::endl;
        handle->data = (void*)((int)handle->data + 1);
        if(int(handle->data) == 8) {
            uv_idle_stop(handle);
            uv_close((uv_handle_t*)handle, [](uv_handle_t* handle) {
                std::cout << "idle1 closed" << std::endl;
            });
        }
    });

    uv_prepare_t prepare1;
    prepare1.data = (void*)2;
    uv_prepare_init(loop, &prepare1);
    uv_prepare_start(&prepare1, [](uv_prepare_t* handle) {
        std::cout << "prepare1 in " << (int)handle->data << std::endl;
        handle->data = (void*)((int)handle->data + 1);
        if(int(handle->data) == 3) {
            uv_prepare_stop(handle);
            uv_close((uv_handle_t*)handle, [](uv_handle_t* handle) {
                std::cout << "prepare1 closed" << std::endl;
            });
        }
    });

    net_interface();

    uv_run(loop, UV_RUN_DEFAULT);
    return 0;
}