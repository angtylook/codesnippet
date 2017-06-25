#include <thread>
#include <iostream>
#include <cstdlib>
#include "ostreamlock.h"
#include "thread_utils.h"

using namespace std;

static void greet(size_t id) {
    for(size_t i = 0; i < id; i++) {
        cout << oslock << "Greeter #" << id << " says 'Hello!'" << endl << osunlock;
        sleep_for(random() % 1000);
    }
    cout << oslock << "Greeter #" << id << " has issused all of his hellos, "
    << "so he goes home!" << endl << osunlock;
}

static const size_t kNumGreeters = 6;
int main(int argc, char* argv[]) {
    srandom(time(NULL));
    cout << "Welcom to Greetland!" << endl;
    thread greeters[kNumGreeters];
    for(size_t i = 0; i < kNumGreeters; i++)
        greeters[i] = thread(greet, i+1);
    for(thread& greeter: greeters)
        greeter.join();
    cout << "Everyone's all greeted out!" << endl;
    return 0;
}
