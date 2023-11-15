### SETUP ###
cmake_minimum_required (VERSION 3.0)
set(PROJ_NAME Car_Info)
project(${PROJ_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-pthread -std=c++11 -fsanitize=thread -g ")

### PACKAGES ###
find_package(Python3 COMPONENTS Development)
find_package(Boost REQUIRED COMPONENTS python3)
find_package(CommonAPI REQUIRED)
find_package(CommonAPI-SomeIP REQUIRED)

### VARIABLES ###
set(PRJ_SRC_VAR src)
set(PRJ_SRC_GEN_VAR src-gen)
set(PRJ_SRC_GEN_PATH ${CMAKE_CURRENT_SOURCE_DIR}/${PRJ_SRC_GEN_VAR})
set(CORE_GEN_SRC_DIR ${PRJ_SRC_GEN_PATH}/core)
set(SOMEIP_GEN_SRC_DIR ${PRJ_SRC_GEN_PATH}/someip)
set(CORE_RUNTIME_DIR ~/capicxx-core-runtime)
set(SOMEIP_RUNTIME_DIR ~/capicxx-someip-runtime)
set(VSOMEIP_DIR ~/vsomeip)
set(COMMONAPI_INTERFACE_VER v0/commonapi)

### DIRECTORIES ###
include_directories(
	./include
	${Python3_INCLUDE_DIRS}
    ${CORE_GEN_SRC_DIR}
    ${SOMEIP_GEN_SRC_DIR}
    ${SOMEIP_RUNTIME_DIR}/include
    ${CORE_RUNTIME_DIR}/include
    ${VSOMEIP_DIR}/include
)

link_directories(
    ${SOMEIP_RUNTIME_DIR}/build
    ${CORE_RUNTIME_DIR}/build
    ${VSOMEIP_DIR}/build
)

### BUILD ###
# Services
add_executable(CarInfoService 
    ${PRJ_SRC_VAR}/PiRacer.cpp
    ${PRJ_SRC_VAR}/CarInfoService.cpp
    ${PRJ_SRC_VAR}/CarInfoStubImpl.cpp
    ${SOMEIP_GEN_SRC_DIR}/${COMMONAPI_INTERFACE_VER}/CarInfoSomeIPStubAdapter.cpp
    ${SOMEIP_GEN_SRC_DIR}/${COMMONAPI_INTERFACE_VER}/CarInfoSomeIPDeployment.cpp
)
target_link_libraries(CarInfoService 
    CommonAPI 
    CommonAPI-SomeIP 
    vsomeip3
    Python3::Python 
    Boost::python
)
# Client 
add_executable(CarInfoClient
    ${PRJ_SRC_VAR}/CarInfoClient.cpp
    ${SOMEIP_GEN_SRC_DIR}/${COMMONAPI_INTERFACE_VER}/CarInfoSomeIPProxy.cpp
    ${SOMEIP_GEN_SRC_DIR}/${COMMONAPI_INTERFACE_VER}/CarInfoSomeIPDeployment.cpp
)
target_link_libraries(CarInfoClient 
    CommonAPI 
    CommonAPI-SomeIP 
    vsomeip3
)
