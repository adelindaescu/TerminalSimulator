cmake_minimum_required(VERSION 2.8.12.2)
project(TerminalSimulator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(COMPILE_FLAGS "-ledit")
include_directories( /usr/include/editline/ )

set(HELLO_SOURCE_FILES
        internalCommands/hello.c)

add_executable(hello ${HELLO_SOURCE_FILES})

set(TAIL_SOURCE_FILES
        internalCommands/tail.c)

add_executable(tail ${TAIL_SOURCE_FILES})

set(UNIQ_SOURCE_FILES
        internalCommands/uniq.c)

add_executable(uniq ${UNIQ_SOURCE_FILES})

set(SOURCE_FILES
    CMakeLists.txt
    parser.c
    parser.h
    pathBuilder.c
    pathBuilder.h
    terminalSimulator.c
    internalCommands/cd.c
    internalCommands/cd.h)

add_executable(TerminalSimulator ${SOURCE_FILES})
