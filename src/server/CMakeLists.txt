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
        src/HelloWorldClient.cpp
        src-gen-hello/v1/commonapi/E1HelloWorldSomeIPProxy.cpp
        src-gen-hello/v1/commonapi/E1HelloWorldSomeIPDeployment.cpp
)
target_link_libraries(HelloWorldClient CommonAPI CommonAPI-SomeIP vsomeip3)
add_executable(HelloWorldService
        src/HelloWorldService.cpp
        src/HelloWorldStubImpl.cpp
        src-gen-hello/v1/commonapi/E1HelloWorldSomeIPStubAdapter.cpp
        src-gen-hello/v1/commonapi/E1HelloWorldSomeIPDeployment.cpp
)
target_link_libraries(HelloWorldService CommonAPI CommonAPI-SomeIP vsomeip3)