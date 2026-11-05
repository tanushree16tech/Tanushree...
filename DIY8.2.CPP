#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

using namespace std;

class Logger {
public:
    virtual void write(const string &message) = 0;
    virtual ~Logger() = default;
};

class ConsoleLogger : public Logger {
public:
    void write(const string &message) override {
        cout << message << endl;
    }
};

class FileLogger : public Logger {
    ofstream output;

public:
    explicit FileLogger(const string &filename) : output(filename, ios::app) {
        if (!output)
            throw runtime_error("Could not open log file: " + filename);
    }

    void write(const string &message) override {
        output << message << endl;
        if (!output)
            throw runtime_error("Could not write to log file");
    }
};

int main(int argc, char *argv[]) {
    const string mode = argc > 1 ? argv[1] : "console";
    unique_ptr<Logger> logger;

    try {
        if (mode == "console") {
            logger = make_unique<ConsoleLogger>();
        } else if (mode == "file") {
            logger = make_unique<FileLogger>("DIY82.log");
        } else {
            cerr << "Usage: DIY82.EXE [console|file]" << endl;
            return 1;
        }

        logger->write("Logger is working");
    } catch (const exception &error) {
        cerr << "Logging error: " << error.what() << endl;
        return 1;
    }

    return 0;
}