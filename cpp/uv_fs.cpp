#include <iostream>
#include <cstdio>
#include <filesystem>

#include "uv.h"

char buffer[120];
int buffer_len = sizeof(buffer);
uv_buf_t buf;

uv_fs_t open_req;
uv_fs_t read_req;
uv_fs_t write_req;
uv_fs_t close_req;

void on_close(uv_fs_t* req) {
  fprintf(stderr, "on close %Id\n", req->result);
}

void on_read(uv_fs_t* req);

void on_write(uv_fs_t* req) {
    if (req->result < 0) {
        fprintf(stderr, "Write error: %s\n", uv_strerror((int)req->result));
    } else {
        uv_fs_read(uv_default_loop(), &read_req, open_req.result, &buf, 1, -1, on_read);
    }
};

void on_read(uv_fs_t* req) {
    if (req->result < 0) {
        fprintf(stderr, "on read error %s\n", uv_strerror(req->result));
    }else if(req->result == 0){
        uv_fs_close(uv_default_loop(), &close_req, req->result, on_close);
    } else if(req->result > 0) {
        //printf("read: %s \n", buffer);
        buf.len = req->result;
        uv_fs_write(uv_default_loop(), &write_req, 1, &buf, 1, -1, on_write);
    }
}

void on_open(uv_fs_t* req) {
    if(req->result >= 0) {
        buf = uv_buf_init(buffer, buffer_len);
        uv_fs_read(uv_default_loop(), &read_req, req->result, &buf, 1, -1, on_read);
    } else {
        fprintf(stderr, "on open error %s\n", uv_strerror(req->result));
    }
}

int main()
{
    std::cout << "cwd: " << std::filesystem::current_path() << std::endl;

    uv_loop_t* loop = uv_default_loop();
    uv_fs_open(loop, &open_req, "../../cpp/uv_fs.cpp", O_RDONLY, 0, on_open);
    uv_run(loop, UV_RUN_DEFAULT);

    uv_fs_req_cleanup(&open_req);
    uv_fs_req_cleanup(&read_req);
    uv_fs_req_cleanup(&write_req);
    uv_fs_req_cleanup(&close_req);

    uv_pipe_t stdin_pipe;
    uv_pipe_init(loop, &stdin_pipe, 0);
    uv_pipe_open(&stdin_pipe, 0);

    uv_pipe_t stdout_pipe;
    uv_pipe_init(loop, &stdout_pipe, 0);
    uv_pipe_open(&stdout_pipe, 1);

    uv_read_start((uv_stream_t*)&stdin_pipe, [](uv_handle_t* handle, size_t suggested_size, uv_buf_t* inbuf){
        *inbuf = uv_buf_init(buffer, buffer_len);
    }, [](uv_stream_t* stream, ssize_t nread, const uv_buf_t* buf) {
        if (nread < 0) {
            if (nread != UV_EOF)
                fprintf(stderr, "Read error: %s\n", uv_strerror(nread));
            uv_close((uv_handle_t*)stream, NULL);
        } else if (nread > 0) {
            uv_write_t* req = (uv_write_t*)malloc(sizeof(uv_write_t));
            uv_buf_t* b = &uv_buf_init((char*)malloc(nread), nread);
            req->data = (void*)b;
            uv_write(req, stream, buf, 1, [](uv_write_t* req, int status) {
                if (status < 0) {
                    fprintf(stderr, "Write error: %s\n", uv_strerror(status));
                }
                free(req);
            });
        }
    }, NULL);


    return 0;
}