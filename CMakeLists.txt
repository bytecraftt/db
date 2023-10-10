cmake_minimum_required(VERSION 3.0)

project(db)

set(CMAKE_CXX_STANDARD 17)

set(INCLUDES 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/config/include
    ${CMAKE_CURRENT_SOURCE_DIR}/config/json/include
    ${CMAKE_CURRENT_SOURCE_DIR}/config/trace/include
    ${CMAKE_CURRENT_SOURCE_DIR}/connector/mysql/jdbc
    ${CMAKE_CURRENT_SOURCE_DIR}/connector/mysql/jdbc/driver
    ${CMAKE_CURRENT_SOURCE_DIR}/connector/mysql/jdbc/cppconn
    ${CMAKE_BINARY_DIR}/connector/mysql/jdbc/cppconn)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/DataBase.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/MySQLDriver.cpp)

set(LIBRARIES
    ${CMAKE_BINARY_DIR}/connector/mysql/jdbc)

add_subdirectory(config)
add_subdirectory(connector/mysql/jdbc)

link_directories(${LIBRARIES})
include_directories(${INCLUDES})

add_library(dblib STATIC ${SOURCES})
link_libraries(configlib tracelib dblib connector-jdbc)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/db.cpp)