cmake_minimum_required(VERSION 3.14)

project(DES_Project3_IC VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "~/Qt/5.15.15/gcc_64")

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

set(PROJECT_SOURCES
    src/DES_Project3_IC/main.cpp
    src/DES_Project3_IC/ICdatamanager.cpp
    src/DES_Project3_IC/ICdataStubImpl.cpp

    src/Can_Receiver/Can_Data_Register.cpp
    src/Can_Receiver/Can_Moving_Average_Filter.cpp
    src/Can_Receiver/Can_Receiver.cpp

    src/ServiceManager/ServiceManager.cpp
    src/ServiceManager/ServiceManagerSender.cpp
    src/ServiceManager/ServiceManagerStubImpl.cpp

    src/DES_Project3_IC/qml.qrc
)

qt_add_resources(QRC_FILES DES_Project3_IC/qml.qrc)

add_executable(DES_Project3_IC
    ${PROJECT_SOURCES}
    ${QRC_FILES}
)

target_compile_definitions(DES_Project3_IC
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>
)
target_link_libraries(DES_Project3_IC
    PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick
    stdc++
    CommonAPI
    CommonAPI-SomeIP
    vsomeip
)

set_target_properties(DES_Project3_IC PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

