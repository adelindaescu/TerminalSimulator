cmake_minimum_required(VERSION 2.8.12.2)
project(TerminalSimulator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(HELLO_SOURCE_FILES
        internalCommands/hello.c)

add_executable(hello ${HELLO_SOURCE_FILES})


set(SOURCE_FILES
    CMakeLists.txt
    parser.c
    parser.h
    pathBuilder.c
    pathBuilder.h
    terminalSimulator.c)

add_executable(TerminalSimulator ${SOURCE_FILES})
