#pragma once
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <chrono>
#include <ctime>
#include <thread>
#include "LoggerParams.h"

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
                    std::cout << "\x1b[" << infoColor.foreground << "m\x1b[" <<  infoColor.background << 'm' << "INFO | [" <<  strtok(std::ctime(&time), "\n") << "] ";
                    break;
                case DEBUG:
                    std::cout << "\x1b[" << debugColor.foreground << "m\x1b[" << debugColor.background << 'm' << "DEBUG | ["  << strtok(std::ctime(&time), "\n") << "] ";
                    break;
                case WARNING:
                    std::cout << "\x1b[" << warningColor.foreground << "m\x1b[" << warningColor.background << 'm' << "WARNING | ["  << strtok(std::ctime(&time), "\n") << "] ";
                    break;
                case ERROR:
                    std::cout << "\x1b[" << errorColor.foreground << "m\x1b[" << errorColor.background << 'm' << "ERROR | ["  << strtok(std::ctime(&time), "\n") << "] ";
                    break;
            }
            (std::cout << "\n\t" << ... << args) << "\x1B[0m\n";
        }

        void setLogColors(LogLevel logLevel, LogColors foreground, LogColors background)
        {
            switch(logLevel)
            {
                case INFO:
                    infoColor.background = background;
                    infoColor.foreground = foreground;
                    break;
                case DEBUG:
                    debugColor.background = background;
                    debugColor.foreground = foreground;
                    break;
                case WARNING:
                    warningColor.background = background;
                    warningColor.foreground = foreground;
                    break;
                case ERROR:
                    errorColor.background = background;
                    errorColor.foreground = foreground;
                    break;
            }
        }

    private:
        TextColor infoColor = {WHITE_TEXT, BLACK_BACKGROUND};
        TextColor debugColor = {GREEN_TEXT, BLACK_BACKGROUND};
        TextColor warningColor = {YELLOW_TEXT, BLACK_BACKGROUND};
        TextColor errorColor = {RED_TEXT, BLACK_BACKGROUND};
};