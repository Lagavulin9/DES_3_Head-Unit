cmake_minimum_required(VERSION 3.15)

project(Can_Receiver_IC VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")
#Debuger

set(CMAKE_INCLUDE_CURRENT_DIR ON)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../build-commonapi/capicxx-core-runtime/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../build-commonapi/capicxx-someip-runtime/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../build-commonapi/vsomeip/interface
    ${CMAKE_CURRENT_SOURCE_DIR}/src-gen-can

)

link_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../build-commonapi/capicxx-core-runtime/build
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../build-commonapi/capicxx-someip-runtime/build
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../build-commonapi/vsomeip/build
)

# For Can_Receiver
set(Can_Receiver_SOURCES
    src/Can_main.cpp
    src/Speed_SensorStubImpl.cpp
    src/Can_Data_Register.cpp
    src/Can_Moving_Average_Filter.cpp
    src/Can_Receiver.cpp

    src-gen-can/v1/Can_Receiver/Speed_SensorSomeIPStubAdapter.cpp
    src-gen-can/v1/Can_Receiver/Speed_SensorSomeIPDeployment.cpp
    )
add_executable(Can_Receiver ${Can_Receiver_SOURCES})
add_library(Can_Receiver_Lib SHARED ${Can_Receiver_SOURCES})
target_link_libraries(Can_Receiver PRIVATE stdc++ CommonAPI CommonAPI-SomeIP vsomeip3)
