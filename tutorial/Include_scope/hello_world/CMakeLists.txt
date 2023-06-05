add_subdirectory(hello)

add_library(hello_world hello_world.c)

target_link_libraries(hello_world PRIVATE hello)

target_include_directories(hello_world
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )