### SETUP ###
cmake_minimum_required (VERSION 3.0)
set(PROJ_NAME Car_Info)
project(${PROJ_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-pthread -std=c++11 -fsanitize=thread -g ")

### PACKAGES ###
# python 
find_package(Python3 COMPONENTS Development)
find_package(Boost REQUIRED COMPONENTS python3)
## common api 
find_package(CommonAPI REQUIRED)
find_package(CommonAPI-SomeIP REQUIRED)

### VARIABLES ###
set(PRJ_SRC_GEN_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src-gen-carcontrol)
set(CORE_GEN_SRC_DIR ${PRJ_SRC_GEN_PATH}/core)
set(SOMEIP_GEN_SRC_DIR ${PRJ_SRC_GEN_PATH}/someip)
set(CORE_RUNTIME_DIR ~/capicxx-core-runtime)
set(SOMEIP_RUNTIME_DIR ~/capicxx-someip-runtime)
set(VSOMEIP_DIR ~/vsomeip)
set(PRJ_SRC_PATH src)
set(PRJ_SRC_GEN_PATH src-gen)

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
### FILES ###

### BUILD ###
# Services
add_executable(CarControlService 
    src/GamePad.cpp
    src/PiRacer.cpp
    src/CarControlService.cpp
    src/CarControlStubImpl.cpp
    src-gen-carcontrol/someip/v0/commonapi/CarControlSomeIPStubAdapter.cpp
    src-gen-carcontrol/someip/v0/commonapi/CarControlSomeIPDeployment.cpp
)
target_link_libraries(CarControlService 
    CommonAPI 
    CommonAPI-SomeIP 
    vsomeip3
    Python3::Python 
    Boost::python
)
# Client 
add_executable(CarControlClient
    src/CarControlClient.cpp
    src-gen-carcontrol/someip/v0/commonapi/CarControlSomeIPProxy.cpp
    src-gen-carcontrol/someip/v0/commonapi/CarControlSomeIPDeployment.cpp
)
target_link_libraries(CarControlClient 
    CommonAPI 
    CommonAPI-SomeIP 
    vsomeip3
)
