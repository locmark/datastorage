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

#include "../logger/Logger.hpp"
#include "../exec/Exec.hpp"

#define fileName "logs.txt"

using namespace std;

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
        }
    public:
        FileLogger() {
            exec("touch logs.txt");
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