#include "logger.h"

char* Logger::getDate()
{
    time_t t = time(nullptr);
    tm *cur_t = localtime(&t);
    char* temp = new char[20];
    strftime(temp, 20 , "%Y-%m-%d %H:%M:%S", cur_t);
    return temp;
}

void Logger::logFile(const std::string& msgLog, const std::string& path)
{
    fout->open(path,std::ofstream::app);
    if(!fout->is_open())
        throw std::runtime_error("\nFile not open!\n");
    else
    {
        *fout << getDate() << " - " << msgLog << std::endl;
    }
    fout->close();
}

void Logger::logConsole(const std::string& msgLog)
{
    std::cout << '\n' << getDate() << " - " << msgLog << std::endl;
}

void Logger::log(const std::string& msgLog, const std::string& path)
{
    logFile(msgLog, path);
    logConsole(msgLog);
}

Logger::~Logger()
{
    delete fout;
}