#include "Progress.h"
#include <cwchar>

void ShowConsoleCursor(bool showFlag);
void Loader(int &load);

int main()
{
    // Loading time in ms
    int load = 35;

    // Hide console cursor
    ShowConsoleCursor(false);
    system("color 0A");

    // Define monitoring process
    CpuMonitor cpu;

    // Define progress indicators
    CpuProgress cpr;
    MemProgress mpr;

    while (true) {

        // Load up virtual memory display
        Loader(load);
        mpr.showVirtualMem();
        std::cout << std::endl;

        // Load up physical memory display
        Loader(load);
        mpr.showPhysicalMem();
        std::cout << std::endl;

        // Load up cpu display
        Loader(load);
        cpr.showCpu(cpu.getCurrentValue());

        // Line skipper, modify to keep more lines 
        std::cout << "\033[3A";
    }
    
    return 0;

}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
void Loader(int &load)
{
    std::cout << '|' << '\r';
    Sleep(load);
    std::cout << '/' << '\r';
    Sleep(load);
    std::cout << '-' << '\r';
    Sleep(load);
    std::cout << '\\' << '\r';
}

// GPU?
// disk space?
// print it on console as a progress bar
