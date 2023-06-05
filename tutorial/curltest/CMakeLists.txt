cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(curltest VERSION 1.0)
find_package(CURL)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# add the executable
add_executable(curltest curltest.cpp)

if(CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIR})
    target_link_libraries(curltest ${CURL_LIBRARY})
else(CURL_FOUND)
    message(FATAL_ERROR "curl not found!")
endif(CURL_FOUND)