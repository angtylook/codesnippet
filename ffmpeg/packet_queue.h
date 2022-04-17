#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>

extern "C" {
// #include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
// #include <libavutil/imgutils.h>
// #include <libswscale/swscale.h>
}

class PacketQueue {
 public:
  PacketQueue() = default;
  void Push(AVPacket* packet);
  AVPacket* Pop();
 private:
  std::queue<AVPacket*> q_;
  std::mutex m_;
  std::condition_variable cv_;
};

