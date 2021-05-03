cmake_minimum_required (VERSION 3.8)

ADD_LIBRARY(stringtochar "stchar.h" "stchar.cxx")
target_include_directories(stringtochar INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_compile_features(stringtochar PUBLIC cxx_std_11)
add_library(sharks::stringtochar ALIAS stringtochar)
