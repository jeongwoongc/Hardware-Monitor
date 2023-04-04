#include "CpuMonitor.h"
#include "MemoryMonitor.h"


int main() 
{
    CpuMonitor cpu;
    MemoryMonitor mem;

    while (true) {
        double cpuusage = cpu.getCurrentValue();
        std::cout << "the total vitual memory available is: " << std::setprecision(4) << mem.virtualMemAvail() << '\n';
        std::cout << "the total vitual memory used is: " << std::setprecision(4) << mem.virtualMemUsed() << '\n';
        std::cout << "the total physical memory available is: " << std::setprecision(4) << mem.physicalMemAvail() << '\n';
        std::cout << "the total physical memory used is: " << std::setprecision(4) << mem.physicalMemUsed() << '\n';
        std::cout << "the total cpu usage: " << cpuusage << "%" << '\n';
    }
}



// GPU?
// disk space?
// get QT and make a GUI app
