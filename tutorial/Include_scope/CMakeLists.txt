cmake_minimum_required(VERSION 3.10)

# set the project name
project(hello_world_test)
add_subdirectory(hello_world)
# add the executable
add_executable(hello_world_private main.c)
target_link_libraries(hello_world_private hello_world)
