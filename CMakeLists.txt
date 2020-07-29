cmake_minimum_required(VERSION 3.5)

project(hw7 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR src)
set(SOURCES main.cpp ${SRC_DIR}/port.cpp ${SRC_DIR}/vintage_port.cpp)
set(INCLUDES include)

add_executable(hw7 ${SOURCES})
target_include_directories(hw7 PUBLIC ${INCLUDES})

