#include <Logger.hpp>

#include <cstdarg>
#include <cstdio>

Logger Logger::instance;
Logger* Logger::getInstance() {
    return &instance;
}

void Logger::init(LogLevel level, FILE* destination) {
    assert(!initialized);
    assert(destination != nullptr);
    level_ = level;
    destination_ = destination;
    initialized = true;
}

void Logger::log(LogLevel level, const char* format, ...) {
    assert(initialized);
    if(static_cast<int>(level) < static_cast<int>(level_)) return;
    
    va_list arguments;
    va_start(arguments, format);
    vfprintf(destination_, format, arguments);
    va_end(arguments);
}