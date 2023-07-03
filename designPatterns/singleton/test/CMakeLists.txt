find_package(Threads REQUIRED)

include_directories(..)
include_directories(../src)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

find_package(GTest REQUIRED)
include_directories(${GTest_INCLUDE_DIRS})
link_directories(${GTest_LIBRARY_DIRS})

link_directories(/usr/lib/x86_64-linux-gnu/)


set (TESTSOURCES
    main.cpp
)

set(TESTNAME "singletonTests")

ADD_EXECUTABLE(TESTNAME ${TESTSOURCES})

# Link test executable against gtest & gtest_main
target_link_libraries(TESTNAME gtest pthread -lgtest -lgmock gtest_main )

add_test(NAME TESTNAME
          COMMAND TESTNAME)                    