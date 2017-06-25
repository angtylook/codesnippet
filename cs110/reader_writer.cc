#include <mutex>
#include <thread>
#include <iostream>
#include "ostreamlock.h"
#include "random_generator.h"
#include "semaphore.h"
#include "thread_utils.h"

using namespace std;

static const unsigned int kLowPrepareTime = 10;
static const unsigned int kHightPrepareTime = 100;
static const unsigned int kLowProcessTime = 20;
static const unsigned int kHighProcessTime = 120;

static mutex rgenLock;
static RandomGenerator rgen;

static unsigned int getSleepDuration(unsigned int low, unsigned int high) {
    lock_guard<mutex> lg(rgenLock);
    return rgen.getNextInt(low, high);
}

static char prepareData() {
    sleep_for(getSleepDuration(kLowPrepareTime, kHightPrepareTime));
    lock_guard<mutex> lg(rgenLock);
    return rgen.getNextInt('A', 'Z');
}

static void processData(char ch) {
    sleep_for(getSleepDuration(kLowProcessTime, kHighProcessTime));
}

static const unsigned int kNumBuffers = 8;
static const unsigned int kNumCycles = 40;

static char buffer[kNumBuffers];
static semaphore fullBuffers(0);
static semaphore emptyBuffers(kNumBuffers);

static void writer() {
    cout << oslock << "Writer: ready to write." << endl << osunlock;
    for(unsigned int i = 0; i < kNumCycles * kNumBuffers; i++) {
        char ch = prepareData();
        emptyBuffers.wait();
        buffer[i % kNumBuffers] = ch;
        fullBuffers.signal();
        cout << oslock << "Writer: published data packet with character'"
             << ch << "'." << endl << osunlock;
    }
}

static void reader() {
    cout << oslock << "\t\tReader: ready to read." << endl << osunlock;
    for(unsigned int i = 0; i < kNumCycles * kNumBuffers; i++) {
        fullBuffers.wait();
        char ch = buffer[i % kNumBuffers];
        emptyBuffers.signal();
        processData(ch);
        cout << oslock << "\t\tReader: consumed data packet "
             << "with character '" << ch << "'." << endl << osunlock;
    }
}

int main(int argc, const char* argv[]) {
    thread w(writer);
    thread r(reader);
    w.join();
    r.join();
    return 0;
}
