cmake_minimum_required(VERSION 3.8)
project(rush_01)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp IMonitorModule.cpp TimeModule.cpp CpuModule.cpp RawModule.cpp Display.cpp OsModule.cpp HostModule.cpp IMonitorDisplay.cpp Module.cpp)
add_executable(rush_01 ${SOURCE_FILES})