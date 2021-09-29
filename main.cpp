#include "logger.h"

int main() {
    Logger logger("../log.txt");
    logger.log("hello");
    logger.log("world");

    return 0;
}
