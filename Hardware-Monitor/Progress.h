#pragma once

#include "CpuMonitor.h"
#include "MemoryMonitor.h"


class MemProgress : public MemoryMonitor{
public:
    DWORDLONG &totalmem = memInfo.ullTotalPhys;
    DWORDLONG &totalvirtmem = memInfo.ullTotalVirtual;

    void showVirtualMem() {

        double virtmemavail = virtualMemAvail();
        double virtmemused = virtualMemUsed();
        std::cout << "  Virtual Memory committed: [";
        double converted = virtmemused / virtmemavail;
        int res = (converted * 100) / 4;

        for (int i = 0; i < res; ++i) {
            std::cout << "|";
        }
        for (int i = res; i < 25; ++i) {
            std::cout << " ";
        }
        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        std::cout << "] " << virtmemused << " / " << virtmemavail << " gb \b" << '\r';
        fflush(stdout);

    }
    void showPhysicalMem() {

        double tot = ((totalmem / DIV) / DIVGB) * COMP;
        double physmemavail = physicalMemAvail();
        double physmemused = physicalMemUsed();
        std::cout << "  Physical Memory in use:   [";
        double converted = physmemused / tot;
        int res = (converted * 100) / 4;

        for (int i = 0; i < res; ++i) {
            std::cout << "|";
        }
        for (int i = res; i < 25; ++i) {
            std::cout << " ";
        }


        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        std::cout << "] " << physmemused << " / " << tot << " gb \b" << '\r';
        fflush(stdout);
        
    }
    
};

class CpuProgress {
public:
    
    void showCpu(double cpu) {
        int val = cpu;
        std::cout << "  CPU status:               [";
        int bars = cpu / 4; // 25 bars for every 100%
        for (int i = 0; i < bars; ++i) {
            std::cout << "|";
        }
        for (int i = bars; i < 25; ++i) {
            std::cout << " ";
        }

        std::cout << "] " << val << " %  \b" << '\r';
        fflush(stdout);
        
    }


};
