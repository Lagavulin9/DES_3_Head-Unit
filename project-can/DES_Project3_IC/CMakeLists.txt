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
    ${CMAKE_CURRENT_SOURCE_DIR}/../Moderator/src-gen-moderator
   

)

link_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../build-commonapi/capicxx-core-runtime/build
    ${CMAKE_CURRENT_SOURCE_DIR}/../build-commonapi/capicxx-someip-runtime/build
    ${CMAKE_CURRENT_SOURCE_DIR}/../build-commonapi/vsomeip/build
)

find_package(QT NAMES Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)

# For DES_Project3_IC
set(DES_Project3_IC_SOURCES
    src/IC_main.cpp
    src/ICdatamanager.cpp
    src/qml.qrc

    ../Moderator/src-gen-moderator/v1/Moderator/ServiceManagerSomeIPProxy.cpp
    ../Moderator/src-gen-moderator/v1/Moderator/ServiceManagerSomeIPDeployment.cpp
    
    
)
add_executable(DES_Project3_IC ${DES_Project3_IC_SOURCES})
add_library(DES_Project3_IC_Lib SHARED ${DES_Project3_IC_SOURCES})
target_link_libraries(DES_Project3_IC PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick stdc++ CommonAPI CommonAPI-SomeIP vsomeip3 )
target_link_libraries(DES_Project3_IC_Lib PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick stdc++ CommonAPI CommonAPI-SomeIP vsomeip3 )