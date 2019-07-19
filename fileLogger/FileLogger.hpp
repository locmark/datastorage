#ifndef __FILELOGGER
#define __FILELOGGER

#include <iostream>
#include <ctime>
#include <cstring>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#include "../logger/Logger.hpp"

#define fileName "logs.txt"

using namespace std;

static std::string my_exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

class FileLogger {
    private:
        fstream file;

        void PrintTime() {
            time_t t = time(0);
            tm* now = localtime(&t);
            
            file << std::setfill('0') << std::setw(2) << now->tm_hour;
            file << ":";
            file << std::setfill('0') << std::setw(2) << now->tm_min;
            file << ":";
            file << std::setfill('0') << std::setw(2) << now->tm_sec;

            struct timeval  tv;
            gettimeofday(&tv, NULL);

            file << ":";
            file << std::setfill('0') << std::setw(2) << tv.tv_usec;
        }
    public:
        FileLogger() {
            my_exec("touch logs.txt");
            file.open(fileName, ios::out | ios::app);
            if(!file.good()){
                logger->Error("file logger", "file open failed");
                cout << "good() = " << file.good() << endl;
                cout << "eof() = " << file.eof() << endl;
                cout << "fail() = " << file.fail() << endl;
                cout << "bad() = " << file.bad() << endl;
            } else {
                logger->Log("file logger", "Init complete");
            }

        }

        ~FileLogger() {
            file.close();
        }

        void Log(const char* source, const char* msg) {
            PrintTime();
            file << ';' << source << ';' << msg << endl;
        }
};

extern FileLogger* fileLogger;

#endif
