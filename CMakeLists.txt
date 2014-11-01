cmake_minimum_required(VERSION 2.8.4)
project(TerminalSimulator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c;parser.c;pathBuilder.c)
add_executable(TerminalSimulator ${SOURCE_FILES})