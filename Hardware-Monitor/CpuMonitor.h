// CpuMonitor.h : Header file for initiating performance data helper queries for CPU

#pragma once

#include <Pdh.h>
#include <PdhMsg.h>

static PDH_HQUERY cpuQuery;
static PDH_HCOUNTER cpuTotal;

class CpuMonitor {
public:
    const double DIVGB = 10000000;

    void initCPU() {
        PDH_STATUS a = PdhOpenQuery(NULL, 0, &cpuQuery);
        PDH_STATUS i = PdhAddEnglishCounter(cpuQuery, TEXT("\\Processor(_Total)\\% Processor Time"), 0, &cpuTotal);
        PdhCollectQueryData(cpuQuery);
        Sleep(1000);
    }

    double getCurrentValue() {
        initCPU();
        PDH_FMT_COUNTERVALUE counterVal;
        PdhCollectQueryData(cpuQuery);
        PdhGetFormattedCounterValue(cpuTotal, PDH_FMT_DOUBLE, NULL, &counterVal);
        return counterVal.doubleValue;
    }
};