#ifndef __LOGGER
#define __LOGGER

#include <iostream>
#include <ctime>
#include <cstring>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

#define COLOR_RED "\033[;1;31m"
#define COLOR_END "\033[0m"

// TODO: make msg buffer, to avoid multi-thread problems

class Logger
{
private:
    string GetTimeString() {
        time_t t = time(0);
        tm* now = localtime(&t);

        stringstream ss;
        ss << std::setfill('0') << std::setw(2) << now->tm_hour;
        ss << ":";
        ss << std::setfill('0') << std::setw(2) << now->tm_min;
        ss << ":";
        ss << std::setfill('0') << std::setw(2) << now->tm_sec;

        return ss.str();
    }
public:
    void Log(const char* source, const char* msg) {
        cout << '[' << GetTimeString() << "][" << source << "] " << msg << endl;
    }

    void Error(const char* source, const char* msg) {
        cout << COLOR_RED << '[' << GetTimeString() << "][" << source << "][error] " << msg << COLOR_END << endl;
    }
};

extern Logger* logger;


#endif