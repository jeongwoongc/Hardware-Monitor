// MemoryMonitor.h : virtual memory/physical memory stack initializer

#pragma once

#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <iomanip>

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

// Use to convert bytes to GB
#define DIV 1024

class MemoryMonitor {
public:
    const double DIVGB = 1000000;
    const double COMP = 0.9489;
    MEMORYSTATUSEX memInfo;

    double virtualMemAvail() {
        memInfo.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&memInfo);
        DWORDLONG virtualMemAvail = memInfo.ullTotalPageFile;
        return ((virtualMemAvail / DIV) / DIVGB) * COMP;
    }
    double  virtualMemUsed() {
        memInfo.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&memInfo);
        DWORDLONG virtualMemUsed = memInfo.ullTotalPageFile - memInfo.ullAvailPageFile;
        return ((virtualMemUsed / DIV) / DIVGB)* COMP;
    }
    double physicalMemAvail() {
        memInfo.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&memInfo);
        DWORDLONG physicalMemAvail = memInfo.ullAvailPhys;
        return ((physicalMemAvail / DIV) / DIVGB)* COMP;
    }
    double physicalMemUsed() {
        memInfo.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&memInfo);
        DWORDLONG physicalMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;
        return ((physicalMemUsed / DIV) / DIVGB)* COMP;
    }
};
