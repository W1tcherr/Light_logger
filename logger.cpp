#include "logger.h"

std::string Logger::getDate()
{
    using namespace std::chrono;
    using namespace std::string_view_literals;

    std::stringstream temp;

    auto const now = system_clock::now();
    auto now_time = system_clock::to_time_t(now);
    auto ms = duration_cast<milliseconds>(now.time_since_epoch()).count() % 1000;
    auto gm_time = std::gmtime(&now_time);

    temp << "["sv
       << std::put_time(gm_time, "%H:%M:%S") << "."sv << ms << " "sv
       << std::put_time(gm_time, "%d.%m.%Y") << "] "sv;

    return temp.str();
}

void Logger::logFile(const std::string& msgLog, const std::string& path)
{
    std::lock_guard<std::mutex> guard(mtx);
    fout->open(path,std::ofstream::app);
    if(!fout->is_open())
        throw std::runtime_error("\nFile not open!\n");
    else
    {
        *fout << getDate() << " - " << std::this_thread::get_id() << " - " << msgLog << std::endl;
    }
    fout->close();
}

void Logger::logConsole(const std::string& msgLog)
{
    std::lock_guard<std::mutex> guard(mtx);
    std::cout << '\n' << getDate() << " - " << msgLog << std::endl;
}

void Logger::log(const std::string& msgLog, const std::string& path)
{
    logConsole(msgLog);
    logFile(msgLog, path);
}

Logger::~Logger()
{
    delete fout;
}