# Install script for directory: /home/lee/project-can

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib/commonapi/libServiceManagerLib.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/lib/commonapi/libServiceManagerLib.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/lib/commonapi/libServiceManagerLib.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib/commonapi/libServiceManagerLib.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/lib/commonapi" TYPE SHARED_LIBRARY FILES "/home/lee/project-can/build/libServiceManagerLib.so")
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib/commonapi/libServiceManagerLib.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/lib/commonapi/libServiceManagerLib.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/lib/commonapi/libServiceManagerLib.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib/commonapi/libDES_Project3_IC_Lib.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/lib/commonapi/libDES_Project3_IC_Lib.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/lib/commonapi/libDES_Project3_IC_Lib.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib/commonapi/libDES_Project3_IC_Lib.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/lib/commonapi" TYPE SHARED_LIBRARY FILES "/home/lee/project-can/build/libDES_Project3_IC_Lib.so")
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib/commonapi/libDES_Project3_IC_Lib.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/lib/commonapi/libDES_Project3_IC_Lib.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/local/lib/commonapi/libDES_Project3_IC_Lib.so"
         OLD_RPATH "/home/lee/project-can/../build-commonapi/capicxx-core-runtime/build:/home/lee/project-can/../build-commonapi/capicxx-someip-runtime/build:/home/lee/project-can/../build-commonapi/vsomeip/build:/home/lee/Qt/5.15.15/gcc_64/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/lib/commonapi/libDES_Project3_IC_Lib.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib/commonapi/libCan_Receiver_Lib.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/lib/commonapi/libCan_Receiver_Lib.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/lib/commonapi/libCan_Receiver_Lib.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib/commonapi/libCan_Receiver_Lib.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/lib/commonapi" TYPE SHARED_LIBRARY FILES "/home/lee/project-can/build/libCan_Receiver_Lib.so")
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib/commonapi/libCan_Receiver_Lib.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/lib/commonapi/libCan_Receiver_Lib.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/lib/commonapi/libCan_Receiver_Lib.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/lee/project-can/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
