cmake_minimum_required(VERSION 3.5)

#set project name
set(APPNAME "unordered_set")

project(${APPNAME}  VERSION 1.0 DESCRIPTION "custom class with unordered set" LANGUAGES CXX)

find_package (Boost 1.55.0 REQUIRED COMPONENTS system filesystem)

find_package (Boost 1.55.0 REQUIRED COMPONENTS system filesystem)

if (Boost_FOUND)

include_directories (SYSTEM ${Boost_INCLUDE_DIR})

 
  
endif ()
# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)