#ifndef LIGHT_LOGGER_LOGGER_H
#define LIGHT_LOGGER_LOGGER_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

class Logger
{
    static inline std::ofstream *fout = nullptr;
    static char* getDate();

public:
    static void logFile(const std::string& msgLog, const std::string& path);
    static void logConsole(const std::string&);
    static void log(const std::string& msgLog, const std::string& path);
    ~Logger();
};


#endif //LIGHT_LOGGER_LOGGER_H
