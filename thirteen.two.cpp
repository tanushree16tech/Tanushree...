#include <iostream>
#include <string>

using namespace std;

class Logger {
    Logger() = default;

public:
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;

    static Logger &get() {
        static Logger instance;
        return instance;
    }

    void log(const string &message) {
        cout << "[LOG] " << message << endl;
    }
};

int main() {
    Logger::get().log("system up");
    Logger::get().log("same single instance");
    return 0;
}