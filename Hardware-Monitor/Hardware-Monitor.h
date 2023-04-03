// Hardware-Monitor.h : Header file for initiating performance data helper queries/windows

#pragma once

#include <iostream>
#include <Windows.h>
#include <Pdh.h>
#include <PdhMsg.h>
#include <chrono>
#include <thread>
#include <iomanip>

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

static PDH_HQUERY cpuQuery;
static PDH_HCOUNTER cpuTotal;

// Use to convert bytes to GB
#define DIV 1024
double DIVGB = 1000000;