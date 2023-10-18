# Install script for directory: /Users/ericli/Documents/ThetaData/CPP_API_Wrapper/curlcpp/src

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
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Library/Developer/CommandLineTools/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/ericli/Documents/ThetaData/CPP_API_Wrapper/curlcpp/src/libcurlcpp.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcurlcpp.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcurlcpp.a")
    execute_process(COMMAND "/Library/Developer/CommandLineTools/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcurlcpp.a")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/curlcpp" TYPE FILE FILES
    "/Users/ericli/Documents/ThetaData/CPP_API_Wrapper/curlcpp/src/../include/cookie.h"
    "/Users/ericli/Documents/ThetaData/CPP_API_Wrapper/curlcpp/src/../include/cookie_date.h"
    "/Users/ericli/Documents/ThetaData/CPP_API_Wrapper/curlcpp/src/../include/cookie_datetime.h"
    "/Users/ericli/Documents/ThetaData/CPP_API_Wrapper/curlcpp/src/../include/cookie_time.h"
    "/Users/ericli/Documents/ThetaData/CPP_API_Wrapper/curlcpp/src/../include/curl_config.h"
    "/Users/ericli/Documents/ThetaData/CPP_API_Wrapper/curlcpp/src/../include/curl_cookie.h"
    "/Users/ericli/Documents/ThetaData/CPP_API_Wrapper/curlcpp/src/../include/curl_easy.h"
    "/Users/ericli/Documents/ThetaData/CPP_API_Wrapper/curlcpp/src/../include/curl_easy_info.h"
    "/Users/ericli/Documents/ThetaData/CPP_API_Wrapper/curlcpp/src/../include/curl_exception.h"
    "/Users/ericli/Documents/ThetaData/CPP_API_Wrapper/curlcpp/src/../include/curl_form.h"
    "/Users/ericli/Documents/ThetaData/CPP_API_Wrapper/curlcpp/src/../include/curl_global.h"
    "/Users/ericli/Documents/ThetaData/CPP_API_Wrapper/curlcpp/src/../include/curl_header.h"
    "/Users/ericli/Documents/ThetaData/CPP_API_Wrapper/curlcpp/src/../include/curl_info.h"
    "/Users/ericli/Documents/ThetaData/CPP_API_Wrapper/curlcpp/src/../include/curl_interface.h"
    "/Users/ericli/Documents/ThetaData/CPP_API_Wrapper/curlcpp/src/../include/curl_ios.h"
    "/Users/ericli/Documents/ThetaData/CPP_API_Wrapper/curlcpp/src/../include/curl_multi.h"
    "/Users/ericli/Documents/ThetaData/CPP_API_Wrapper/curlcpp/src/../include/curl_option.h"
    "/Users/ericli/Documents/ThetaData/CPP_API_Wrapper/curlcpp/src/../include/curl_pair.h"
    "/Users/ericli/Documents/ThetaData/CPP_API_Wrapper/curlcpp/src/../include/curl_receiver.h"
    "/Users/ericli/Documents/ThetaData/CPP_API_Wrapper/curlcpp/src/../include/curl_sender.h"
    "/Users/ericli/Documents/ThetaData/CPP_API_Wrapper/curlcpp/src/../include/curl_share.h"
    "/Users/ericli/Documents/ThetaData/CPP_API_Wrapper/curlcpp/src/../include/curl_utility.h"
    )
endif()

