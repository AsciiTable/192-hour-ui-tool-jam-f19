cmake_minimum_required(VERSION 3.13)
project(192_hour_ui_tool_jam)

set(CMAKE_CXX_STANDARD 14)


# Find dependencies
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

add_executable(192_hour_ui_tool_jam main.cpp ui_toolkit.cpp ui_toolkit.h notes.cpp notes.h)
target_link_libraries(192_hour_ui_tool_jam ${GTK3_LIBRARIES})

