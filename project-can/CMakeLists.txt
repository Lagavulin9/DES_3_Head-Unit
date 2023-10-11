cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")
include_directories(
    src-gen-manager
    src/ServiceManager
    src/Can_Receiver
    ~/build-commonapi/capicxx-core-runtime/include
    ~/build-commonapi/capicxx-someip-runtime/include
    ~/build-commonapi/vsomeip/interface
)
link_directories(
    ~/build-commonapi/capicxx-core-runtime/build
    ~/build-commonapi/capicxx-someip-runtime/build
    ~/build-commonapi/vsomeip/build
)


add_executable(Can_Receiver
        src/Can_Receiver/Can_Receiver.cpp
        src/Can_Receiver/Can_Moving_Average_Filter.cpp
        src/Can_Receiver/Can_Data_Register.cpp
        src-gen-manager/v1/commonapi/ServiceManagerSomeIPProxy.cpp
        src-gen-manager/v1/commonapi/ServiceManagerSomeIPDeployment.cpp
)
target_link_libraries(Can_Receiver CommonAPI CommonAPI-SomeIP vsomeip3)


add_executable(ServiceManager
        src/ServiceManager/ServiceManager.cpp
        src/ServiceManager/ServiceManagerStubImpl.cpp
        src/ServiceManager/ServiceManagerSender.cpp
        src-gen-manager/v1/commonapi/ServiceManagerSomeIPStubAdapter.cpp
        src-gen-manager/v1/commonapi/ServiceManagerSomeIPDeployment.cpp
)
target_link_libraries(ServiceManager CommonAPI CommonAPI-SomeIP vsomeip3)