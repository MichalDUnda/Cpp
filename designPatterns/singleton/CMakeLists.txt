add_subdirectory(test)
set (SOURCES
multiton.cpp
)
set(APPNAME "multiton")
add_executable(${APPNAME} ${SOURCES})

set(INSTALL_DIR ${CMAKE_BINARY_DIR}/bin)

install(DIRECTORY DESTINATION ${INSTALL_DIR})
install(TARGETS ${APPNAME} DESTINATION ${INSTALL_DIR})







