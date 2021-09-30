#ifndef LIGHT_LOGGER_LOGGER_H
#define LIGHT_LOGGER_LOGGER_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

class Logger
{
    std::ofstream *fout;
public:
    Logger(std::string);
    void log(std::string);
    void logFile(std::string);
    void logConsole(std::string);
    ~Logger();
};


#endif //LIGHT_LOGGER_LOGGER_H
