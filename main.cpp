#include "logger.h"
#include <vector>
#include <thread>

void test_log_function(int second);

int main() {
    std::vector<std::thread> threads;
    threads.reserve(10);
    for(int i = 0 ; i < 10; ++i)
    {
        threads.emplace_back(test_log_function, i);
    }
    for (auto &thr : threads) {
        thr.join();
    }
    return 0;
}

void test_log_function(int second)
{
    for(int i = 0; i < 10; ++i)
    {
        Logger::log("hi", "../log.txt");
        std::this_thread::sleep_for(std::chrono::milliseconds(10*second));
    }
}