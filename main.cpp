#include "logger.h"

// добавить потокобезопастность метода записи в файл

int main() {

    Logger::log("hello","../log.txt");
    Logger::log("world","../log.txt");

    return 0;
}
