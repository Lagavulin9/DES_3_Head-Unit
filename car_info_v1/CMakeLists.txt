set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -fsanitize=address -g")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -g")

cmake_minimum_required(VERSION 3.15)
project(PiRacerInfo)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

add_executable(PiRacerInfo
        main.cpp
        PiRacerInfoClass.cpp
)
target_link_libraries(PiRacerInfo ${PYTHON_LIBRARIES})