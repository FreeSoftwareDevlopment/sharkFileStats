cmake_minimum_required (VERSION 3.8)

ADD_LIBRARY(parser "parser.h" "parser.cxx")
target_include_directories(parser INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_compile_features(parser PUBLIC cxx_std_11)
add_library(sharks::parser ALIAS parser)
