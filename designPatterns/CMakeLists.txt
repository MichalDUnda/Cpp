cmake_minimum_required(VERSION 3.5)

#set project name
set(APPNAME "builder")

project(${APPNAME}  VERSION 1.0 DESCRIPTION "builder" LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

add_subdirectory(fluentBuilder)
add_subdirectory(factories)
add_subdirectory(builderCRTPPattern)
add_subdirectory(prototype)
add_subdirectory(singleton)
add_subdirectory(adapter)
add_subdirectory(bridge)
add_subdirectory(composite)
add_subdirectory(decorator)
add_subdirectory(flyweight)
add_subdirectory(proxy)
add_subdirectory(chainOfResponsibility)
add_subdirectory(brokerChain)
add_subdirectory(ccommand)
add_subdirectory(mediator)
add_subdirectory(state)
add_subdirectory(strategy)
add_subdirectory(test)