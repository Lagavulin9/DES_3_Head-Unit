cmake_minimum_required (VERSION 3.0)
project(Car_Control)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fsanitize=thread -g")

include_directories(
	./include
)

file(GLOB SOURCES "src/*.cpp")

add_executable(control ${SOURCES})