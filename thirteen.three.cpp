#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

long counter = 0;
mutex counterMutex;

void addSafe(int times) {
    for (int i = 0; i < times; ++i) {
        lock_guard<mutex> lock(counterMutex);
        ++counter;
    }
}

int main() {
    thread first(addSafe, 100000);
    thread second(addSafe, 100000);

    first.join();
    second.join();

    cout << "counter = " << counter << " (expected 200000)" << endl;
    if (counter != 200000) {
        cerr << "Counter did not reach the expected total" << endl;
        return 1;
    }

    return 0;
}