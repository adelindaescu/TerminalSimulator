cmake_minimum_required(VERSION 3.3)
project(TerminalSimulator)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")
set(CMAKE_C_FLAGS "-ledit")

set(HELLO_SOURCE_FILES
        internalCommands/hello.c)

add_executable(hello ${HELLO_SOURCE_FILES})


set(SOURCE_FILES
        CMakeLists.txt
        parser.c
        parser.h
        pathBuilder.c
        pathBuilder.h
        internalCommands/cd.c
        internalCommands/cd.h
        terminalSimulator.c)

add_executable(TerminalSimulator ${SOURCE_FILES})
