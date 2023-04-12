cmake_minimum_required(VERSION 3.25)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp)



include_directories(/usr/local/opt/curl/include/)


set(CURL_LIBRARY "-lcurl")
find_package(CURL REQUIRED)


include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(untitled ${CURL_LIBRARIES})
