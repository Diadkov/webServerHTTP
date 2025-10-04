# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(WebServerHTTP LANGUAGES CXX)

set(TARGET_NAME WebServerHTTP)
set(SOURCES
    main.cpp
    src/MultiClientChat.cpp
    src/TcpListener.cpp
    src/WebServer.cpp
)

set(HEADERS
    include/MultiClientChat.h
    include/TcpListener.h
    include/WebServer.h
)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Include sub-projects.
add_executable(${TARGET_NAME} 
${SOURCES} 
${HEADERS})

add_custom_command(TARGET WebServerHTTP POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/wwwroot"
        "$<TARGET_FILE_DIR:WebServerHTTP>/wwwroot"
)
