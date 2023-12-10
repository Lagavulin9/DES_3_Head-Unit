### SETUP ###
cmake_minimum_required(VERSION 3.15)
project(Can_Receiver_IC VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-pthread -std=c++11")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

### PACKAGES ###
find_package(CommonAPI REQUIRED)
find_package(CommonAPI-SomeIP REQUIRED)

#### VARIABLES ####
set(Can_Receiver_SOURCES
    src/main.cpp
    src/SpeedSensorStubImpl.cpp
    src/CanDataRegister.cpp
    src/MovingAverageFilter.cpp
    src/CanReceiver.cpp
)

FILE(GLOB PRJ_SOMEIP_LIB_SRCS ./src-gen/someip/v0/commonapi/*.cpp)

### DIRECTORIES ###
include_directories(
	./include
    ./src-gen/core
    ./src-gen/someip
    ${COMMONAPI_INCLUDE_DIRS}
    ${COMMONAPI_SOMEIP_INCLUDE_DIRS}
)

link_directories(
    ${COMMONAPI_LIBDIR}
    ${COMMONAPI_SOMEIP_CMAKE_DIR}/build
)
#### BUILD ####
# Service
add_executable(CanReceiver 
    ${Can_Receiver_SOURCES}
)
target_link_libraries(CanReceiver CommonAPI)

add_library(CanReceiver-someip
    SHARED ${PRJ_SOMEIP_LIB_SRCS}
)
target_link_libraries(CanReceiver-someip
    CommonAPI
    CommonAPI-SomeIP
)
