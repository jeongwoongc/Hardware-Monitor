# CMakeList.txt : CMake project for Hardware-Monitor, include source and define
# project specific logic here.
# 

# Add source to this project's executable. 
add_executable (Hardware-Monitor "Hardware-Monitor.cpp" "CpuMonitor.h" "MemoryMonitor.h"  "Progress.h" )
target_link_libraries(Hardware-Monitor PRIVATE pdh)
  
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Hardware-Monitor PROPERTY CXX_STANDARD 20)
endif() 

# TODO: Add tests and install targets if needed.
