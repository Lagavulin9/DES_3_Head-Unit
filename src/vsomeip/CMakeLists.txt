project(helloWorld)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

include_directories(
    src-gen-car_control
    ~/build-commonapi/capicxx-core-runtime/include
    ~/build-commonapi/capicxx-someip-runtime/include
    ~/build-commonapi/vsomeip/interface
)

link_directories(
    ~/build-commonapi/capicxx-core-runtime/build
    ~/build-commonapi/capicxx-someip-runtime/build
    ~/build-commonapi/vsomeip/build
)

add_executable(Car_Control_Client
    src/vsomeip/Car_Control.cpp
    src-gen-car_control/v0/commonapi/Car_ControlSomeIPProxy.cpp
    src-gen-car_control/v0/commonapi/Car_ControlSomeIPDeployment.cpp
)
target_link_libraries(Car_Control_Client CommonAPI CommonAPI-SomeIP vsomeip3)

add_executable(Car_Control_Service
    src/vsomeip/Car_Control.cpp
    src/vsomeip/Car_ControlStubImpl.cpp
    src-gen-car_control/v0/commonapi/Car_ControlSomeIPStubAdapter.cpp
    src-gen-car_control/v0/commonapi/Car_ControlSomeIPDeployment.cpp
)
target_link_libraries(Car_Control_Service CommonAPI CommonAPI-SomeIP vsomeip3)

#https://github.com/SEA-ME/Team-Pilot/blob/Moon/Project-2/CommonAPI-vSomeIP/project-can/CMakeLists.txt
