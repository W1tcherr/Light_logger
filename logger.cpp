#include "logger.h"

Logger::Logger(std::string path)
{
    this->fout = new std::ofstream(path,std::ofstream::app);
}

void Logger::log(std::string strLog)
{
    logFile(strLog);
    logConsole(strLog);
}

void Logger::logFile(std::string strLog)
{
    if(!fout->is_open())
        throw std::runtime_error("\nFile not open!\n");
    else
    {
        time_t t = time(NULL);
        tm *cur_t = localtime(&t);
        char tmp[32];
        strftime(tmp, 31 , "%Y-%m-%d %H:%M:%S", cur_t);
        *fout << tmp << " - " << strLog << std::endl;
    }
}
void Logger::logConsole(std::string strLog)
{
    std::cout << '\n' << strLog << std::endl;
}

Logger::~Logger()
{
    delete this->fout;
}