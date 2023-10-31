cmake_minimum_required (VERSION 3.0)
project(Car_Control)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fsanitize=address -g")

find_package(Python3 COMPONENTS Development)
find_package(Boost REQUIRED COMPONENTS python3)

include_directories(
	./include
	${Python3_INCLUDE_DIRS}
)

file(GLOB SOURCES "src/*.cpp")

add_executable(control ${SOURCES})
target_link_libraries(control Python3::Python Boost::python)