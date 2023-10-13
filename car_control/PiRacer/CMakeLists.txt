set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

cmake_minimum_required(VERSION 2.8)
project(PiRacer_Embedded_Python)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

add_executable(PiRacer_Embedded_Python
        main.cpp
        PiRacerClass.cpp
)
target_link_libraries(PiRacer_Embedded_Python ${PYTHON_LIBRARIES})
