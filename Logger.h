#pragma once
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <chrono>
#include <ctime>
enum LogLevel
{
    INFO = 0,
    DEBUG = 1,
    WARNING = 2,
    ERROR = 3,
};

class Logger
{

    public:
        Logger()
        {
            log(INFO, "Logger successfully created!");
            log(DEBUG, "Logger successfully created!");
            log(WARNING, "Logger successfully created!");
            log(ERROR, "Logger successfully created!");
        }
        ~Logger(){};
        template <class... Args>
        void log(LogLevel logLevel, Args... args)
        {
            auto chronoTime = std::chrono::system_clock::now();
            std::time_t time = std::chrono::system_clock::to_time_t(chronoTime);
            switch(logLevel)
            {
                case INFO:
                    std::cout << "\033[1;90;97m INFO | [" <<  strtok(std::ctime(&time), "\n") << "] ";
                    break;
                case DEBUG:
                    std::cout << "\033[1;90;92m DEBG | [" << strtok(std::ctime(&time), "\n") << "] ";
                    break;
                case WARNING:
                    std::cout << "\033[1;90;93m WARN | [" << strtok(std::ctime(&time), "\n") << "] ";
                    break;
                case ERROR:
                    std::cout << "\033[1;90;91m ERRO | [" << strtok(std::ctime(&time), "\n") << "] ";
                    break;
            }
            (std::cout << "\n\t" << ... << args) << "\x1B[0m\n";
        }
};