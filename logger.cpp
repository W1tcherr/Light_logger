#include "logger.h"

Logger::Logger(std::string path)
{
    this->fout = new std::ofstream(path,std::ofstream::app);
}

char* Logger::getData()
{
    time_t t = time(NULL);
    tm *cur_t = localtime(&t);
    char* tmp = new char[20];
    strftime(tmp, 20 , "%Y-%m-%d %H:%M:%S", cur_t);
    return tmp;
}

void Logger::logFile(std::string strLog)
{
    if(!fout->is_open())
        throw std::runtime_error("\nFile not open!\n");
    else
    {
        *fout << getData() << " - " << strLog << std::endl;
    }
}
void Logger::logConsole(std::string strLog)
{
    std::cout << '\n' << getData() << " - " << strLog << std::endl;
}

void Logger::log(std::string strLog)
{
    logFile(strLog);
    logConsole(strLog);
}

Logger::~Logger()
{
    delete this->fout;
}