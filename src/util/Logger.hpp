#ifndef LOGGER
#define LOGGER

#include <LogLevel.hpp>

#include <cassert>
#include <cstdio>

#define LOG_DEBUG(...)  Logger::getInstance()->log(kDEBUG, __VA_ARGS__)
#define LOG_INFO(...)  Logger::getInstance()->log(kINFO, __VA_ARGS__)
#define LOG_ERROR(...)  Logger::getInstance()->log(kERROR, __VA_ARGS__)

class Logger {

public:
    static Logger* getInstance();
    
    void init(LogLevel level, FILE* destination);
    void log(LogLevel level, const char* format, ...);

private:
    Logger() : level_(kDEBUG), destination_(nullptr) {}
    static Logger instance;

    bool initialized;
    LogLevel level_;
    FILE* destination_;


};

#endif