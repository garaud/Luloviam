CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(KALEIDOSCOPE_LLVM)

add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall -pedantic")

include_directories(${PROJECT_SOURCE_DIR}/src)

add_subdirectory(tests)
