cmake_minimum_required(VERSION 3.15)

project(DES_Project3_IC VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")
#Debuger

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../build-commonapi/capicxx-core-runtime/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../build-commonapi/capicxx-someip-runtime/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../build-commonapi/vsomeip/interface
    ${CMAKE_CURRENT_SOURCE_DIR}/src-gen-moderator
    ${CMAKE_CURRENT_SOURCE_DIR}/../Can_Receiver/src-gen-canReceiver
    

)

link_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../build-commonapi/capicxx-core-runtime/build
    ${CMAKE_CURRENT_SOURCE_DIR}/../build-commonapi/capicxx-someip-runtime/build
    ${CMAKE_CURRENT_SOURCE_DIR}/../build-commonapi/vsomeip/build
)

# For ServiceManager
set(ServiceManager_SOURCES
    src/ServiceManager_main.cpp
    src/ServiceManagerReceiver.cpp
    src/ServiceManagerStubImpl.cpp
    
    src-gen-moderator/v1/Moderator/ServiceManagerStubDefault.hpp
    src-gen-moderator/v1/Moderator/ServiceManagerSomeIPDeployment.cpp
    src-gen-moderator/v1/Moderator/ServiceManagerSomeIPStubAdapter.cpp
    
    ../Can_Receiver/src-gen-canReceiver/v1/Can_Receiver/Speed_SensorSomeIPDeployment.cpp
    ../Can_Receiver/src-gen-canReceiver/v1/Can_Receiver/Speed_SensorSomeIPProxy.cpp
    
    # src-gen-moderator/v1/DES_Project3/Car_ControlSomeIPDeployment.cpp
    # src-gen-moderator/v1/DES_Project3/Car_ControlSomeIPProxy.cpp
    
    # src-gen-moderator/v1/DES_Project3/Car_InformationSomeIPDeployment.cpp
    # src-gen-moderator/v1/DES_Project3/Car_InformationSomeIPProxy.cpp
    
    # src-gen-moderator/v1/DES_Project3/HUSomeIPDeployment.cpp
    # src-gen-moderator/v1/DES_Project3/HUSomeIPProxy.cpp
    )
add_executable(ServiceManager ${ServiceManager_SOURCES})
add_library(ServiceManagerLib SHARED ${ServiceManager_SOURCES})
target_link_libraries(ServiceManager PRIVATE stdc++ CommonAPI CommonAPI-SomeIP vsomeip3)
