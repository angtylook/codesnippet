#ifndef _OSTREAM_LOCK_H_
#define _OSTREAM_LOCK_H_

#include <iostream>
#include <mutex>

class Oslock {
  public:
    Oslock(bool l):lock(l) {};
    friend std::ostream& operator<< (std::ostream& os, const Oslock& o);
  private:
    bool lock;
    static std::mutex m;
};

static Oslock oslock(true);
static Oslock osunlock(false);

#endif

