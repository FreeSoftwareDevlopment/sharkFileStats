cmake_minimum_required (VERSION 3.8)

ADD_LIBRARY(drive "getDiskStats/diskstats.h" "getDiskStats/diskstats.cxx" "osspec.h" "global.h")
add_library(sharks::drive ALIAS drive)
add_executable (firstuniversalWINuLINUXcpp "firstuniversalWINuLINUXcpp.cpp" "firstuniversalWINuLINUXcpp.h" "getDiskStats/diskstats.h" "osspec.h" "getDiskStats/diskstats.cxx" "global.h")
target_link_libraries(firstuniversalWINuLINUXcpp sharks::drive sharks::parser sharks::stringtochar)