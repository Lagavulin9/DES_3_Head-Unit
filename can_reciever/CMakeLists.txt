### SETUP ###
cmake_minimum_required(VERSION 3.15)
project(Can_Receiver_IC VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-pthread -std=c++11 -fsanitize=thread -g ")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

### PACKAGES ###
find_package(CommonAPI REQUIRED)
find_package(CommonAPI-SomeIP REQUIRED)

#### VARIABLES ####
set(Can_Receiver_SOURCES
    src/Can_main.cpp
    src/Speed_SensorStubImpl.cpp
    src/Can_Data_Register.cpp
    src/Can_Moving_Average_Filter.cpp
    src/Can_Receiver.cpp
    src-gen-can/v1/Can_Receiver/Speed_SensorSomeIPStubAdapter.cpp
    src-gen-can/v1/Can_Receiver/Speed_SensorSomeIPDeployment.cpp
)
set(PRJ_SRC_VAR src)
set(PRJ_SRC_GEN_VAR src-gen-can)
set(PRJ_SRC_GEN_PATH ${CMAKE_CURRENT_SOURCE_DIR}/${PRJ_SRC_GEN_VAR})
set(GEN_SRC_DIR ${PRJ_SRC_GEN_PATH})
set(CORE_RUNTIME_DIR ~/capicxx-core-runtime)
set(SOMEIP_RUNTIME_DIR ~/capicxx-someip-runtime)
set(VSOMEIP_DIR ~/vsomeip)
set(COMMONAPI_INTERFACE_VER v1/commonapi)

### DIRECTORIES ###
include_directories(
	./include
	${Python3_INCLUDE_DIRS}
    ${GEN_SRC_DIR}
    ${SOMEIP_RUNTIME_DIR}/include
    ${CORE_RUNTIME_DIR}/include
    ${VSOMEIP_DIR}/include
)

link_directories(
    ${SOMEIP_RUNTIME_DIR}/build
    ${CORE_RUNTIME_DIR}/build
    ${VSOMEIP_DIR}/build
)
#### BUILD ####
# Service
add_executable(Can_Receiver 
    ${Can_Receiver_SOURCES}
)
add_library(Can_Receiver_Lib 
    SHARED ${Can_Receiver_SOURCES}
)
target_link_libraries(Can_Receiver 
    PRIVATE stdc++
    CommonAPI 
    CommonAPI-SomeIP 
    vsomeip3
)
