#include "Hardware-Monitor.h"

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

static PDH_HQUERY cpuQuery;
static PDH_HCOUNTER cpuTotal;

// Use to convert bytes to GB
#define DIV 1024
double DIVGB = 1000000;

void initCPU() {
    PDH_STATUS a = PdhOpenQuery(NULL, 0, &cpuQuery);
    PDH_STATUS i = PdhAddEnglishCounter(cpuQuery, TEXT("\\Processor(_Total)\\% Processor Time"), 0, &cpuTotal);
    PdhCollectQueryData(cpuQuery);
    Sleep(1000);
}

double getCurrentValue() {
    initCPU();
    Sleep(500);
    PDH_FMT_COUNTERVALUE counterVal;
    PdhCollectQueryData(cpuQuery);
    PdhGetFormattedCounterValue(cpuTotal, PDH_FMT_DOUBLE, NULL, &counterVal);
    return counterVal.doubleValue;
}

void initMEM() {

    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfo);
    DWORDLONG totalVirtualMem = memInfo.ullTotalPageFile;
    DWORDLONG virtualMemUsed = memInfo.ullTotalPageFile - memInfo.ullAvailPageFile;
    DWORDLONG physicalMemAvail = memInfo.ullAvailPhys;
    DWORDLONG physicalMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;

    std::cout << "Total Virtual Memory available: " << std::setprecision(3) << (totalVirtualMem / DIV) / DIVGB << "GB" << '\n';
    std::cout << "Total Virtual Memory Used: " << std::setprecision(3) << (virtualMemUsed / DIV) / DIVGB << "GB" << '\n';
    std::cout << "Total Physical Memory available: " << std::setprecision(3) << (physicalMemAvail / DIV) / DIVGB << "GB" << '\n';
    std::cout << "Total Physical Memory Used: " << std::setprecision(3) << (physicalMemUsed / DIV) / DIVGB << "GB" << '\n';
    sleep_for(0.5s);
} 

int main()
{
    while (true) {
        // initMEM();
        double CPUUsage = getCurrentValue();
        std::cout << "The Total CPU usage in %: " << CPUUsage << '\n';
    }


    return 0;
}

// Make classes for each monitor
// GPU?
// disk space?
// get QT and make a GUI app
