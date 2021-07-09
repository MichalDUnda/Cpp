cmake_minimum_required(VERSION 3.5)

#set project name
set(APPNAME "vector")

project(${APPNAME}  VERSION 1.0 DESCRIPTION "own vector for education purpuses" LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)