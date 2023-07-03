set (SOURCES
    Person.cpp
    PersonBuilder.cpp
    main.cpp
)
# exacutable
add_executable(${APPNAME} ${SOURCES})

set(INSTALL_DIR ${CMAKE_BINARY_DIR}/bin)

install(DIRECTORY DESTINATION ${INSTALL_DIR})
install(TARGETS ${APPNAME} DESTINATION ${INSTALL_DIR})



