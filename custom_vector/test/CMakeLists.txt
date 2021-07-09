find_package(Threads REQUIRED)

include_directories(..)
include_directories(../src)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

find_package(GTest REQUIRED)
include_directories(${GTest_INCLUDE_DIRS})
link_directories(${GTest_LIBRARY_DIRS})

link_directories(/usr/lib/x86_64-linux-gnu/)


set (TESTSOURCES
    test.cpp
    main.cpp
)

ADD_EXECUTABLE(testfoo ${TESTSOURCES})

# Link test executable against gtest & gtest_main
target_link_libraries(testfoo gtest pthread -lgtest -lgmock gtest_main )

add_test(NAME testfoo
          COMMAND testfoo)                    