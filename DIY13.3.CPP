#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

using namespace std;

int total = 0;
mutex totalMutex;

void addValues(bool useLock) {
    for (int i = 0; i < 100000; ++i) {
        if (useLock) {
            lock_guard<mutex> lock(totalMutex);
            ++total;
        } else {
            ++total;
        }
    }
}

int main(int argc, char *argv[]) {
    const string mode = argc > 1 ? argv[1] : "locked";
    if (mode != "locked" && mode != "race") {
        cerr << "Usage: DIY133.EXE [locked|race]" << endl;
        return 1;
    }

    const bool useLock = mode == "locked";
    vector<thread> workers;
    workers.emplace_back(addValues, useLock);
    workers.emplace_back(addValues, useLock);

    for (thread &worker : workers)
        worker.join();

    cout << (useLock ? "Locked" : "Unprotected race")
         << " total: " << total << endl;
    if (useLock && total != 200000) {
        cerr << "Unexpected total in locked mode" << endl;
        return 1;
    }

    return 0;
}