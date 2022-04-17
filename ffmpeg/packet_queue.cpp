#include "packet_queue.h"

void PacketQueue::Push(AVPacket* packet) {
  {
    std::lock_guard<std::mutex> lg(m_);
    q_.push(packet);
  }
  cv_.notify_one();
}

AVPacket* PacketQueue::Pop() {
  std::unique_lock<std::mutex> ul(m_);
  if (q_.size() > 0) {
    auto p = q_.front();
    q_.pop();
    return p;
  }
  while (q_.size() == 0) {
    cv_.wait(ul, [this] { return !q_.empty(); });
  }
  auto p = q_.front();
  q_.pop();
  return p;
}

