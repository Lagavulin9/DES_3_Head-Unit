cmake_minimum_required(VERSION 3.15)

project(DES_Project3_IC VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")
#Debuger

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "~/Qt/5.15.15/gcc_64/lib/cmake")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../build-commonapi/capicxx-core-runtime/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../build-commonapi/capicxx-someip-runtime/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../build-commonapi/vsomeip/interface
    ${CMAKE_CURRENT_SOURCE_DIR}/src-gen-manager

)

link_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../build-commonapi/capicxx-core-runtime/build
    ${CMAKE_CURRENT_SOURCE_DIR}/../build-commonapi/capicxx-someip-runtime/build
    ${CMAKE_CURRENT_SOURCE_DIR}/../build-commonapi/vsomeip/build
)

find_package(QT NAMES Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)


# For Can_Receiver
set(Can_Receiver_SOURCES
    src/Can_Receiver/Can_main.cpp
    src/Can_Receiver/Speed_SensorStubImpl.cpp
    src/Can_Receiver/Can_Data_Register.cpp
    src/Can_Receiver/Can_Moving_Average_Filter.cpp
    src/Can_Receiver/Can_Receiver.cpp

    src-gen-manager/v1/DES_Project3/Speed_SensorSomeIPStubAdapter.cpp
    src-gen-manager/v1/DES_Project3/Speed_SensorSomeIPDeployment.cpp
    )
add_executable(Can_Receiver ${Can_Receiver_SOURCES})
add_library(Can_Receiver_Lib SHARED ${Can_Receiver_SOURCES})
target_link_libraries(Can_Receiver PRIVATE stdc++ CommonAPI CommonAPI-SomeIP vsomeip3)

# For ServiceManager
set(ServiceManager_SOURCES
    src/ServiceManager/ServiceManager_main.cpp
    src/ServiceManager/ServiceManagerReceiver.cpp
    src/ServiceManager/ServiceManagerStubImpl.cpp
    
    
    src-gen-manager/v1/DES_Project3/ServiceManagerStubDefault.hpp
    src-gen-manager/v1/DES_Project3/ServiceManagerSomeIPDeployment.cpp
    src-gen-manager/v1/DES_Project3/ServiceManagerSomeIPStubAdapter.cpp
    
    src-gen-manager/v1/DES_Project3/Speed_SensorSomeIPDeployment.cpp
    src-gen-manager/v1/DES_Project3/Speed_SensorSomeIPProxy.cpp
    
    src-gen-manager/v1/DES_Project3/Car_ControlSomeIPDeployment.cpp
    src-gen-manager/v1/DES_Project3/Car_ControlSomeIPProxy.cpp
    
    src-gen-manager/v1/DES_Project3/Car_InformationSomeIPDeployment.cpp
    src-gen-manager/v1/DES_Project3/Car_InformationSomeIPProxy.cpp
    
    src-gen-manager/v1/DES_Project3/HUSomeIPDeployment.cpp
    src-gen-manager/v1/DES_Project3/HUSomeIPProxy.cpp
    )
    add_executable(ServiceManager ${ServiceManager_SOURCES})
    add_library(ServiceManagerLib SHARED ${ServiceManager_SOURCES})
    target_link_libraries(ServiceManager PRIVATE stdc++ CommonAPI CommonAPI-SomeIP vsomeip3)
    
    # For DES_Project3_IC
    set(DES_Project3_IC_SOURCES
        src/DES_Project3_IC/IC_main.cpp
        src/DES_Project3_IC/ICdatamanager.cpp
        src/DES_Project3_IC/qml.qrc
    
        src-gen-manager/v1/DES_Project3/ServiceManagerSomeIPProxy.cpp
        src-gen-manager/v1/DES_Project3/ServiceManagerSomeIPDeployment.cpp
        
        
    )
    add_executable(DES_Project3_IC ${DES_Project3_IC_SOURCES})
    add_library(DES_Project3_IC_Lib SHARED ${DES_Project3_IC_SOURCES})
    target_link_libraries(DES_Project3_IC PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick stdc++ CommonAPI CommonAPI-SomeIP vsomeip3 )
    target_link_libraries(DES_Project3_IC_Lib PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick stdc++ CommonAPI CommonAPI-SomeIP vsomeip3 )
# Install .so files to /usr/local/lib/commonapi
install(TARGETS ServiceManagerLib DES_Project3_IC_Lib Can_Receiver_Lib
        LIBRARY DESTINATION /usr/local/lib/commonapi)
