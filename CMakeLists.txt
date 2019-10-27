cmake_minimum_required(VERSION 3.13)
project(192_hour_ui_tool_jam)

set(CMAKE_CXX_STANDARD 14)

add_executable(192_hour_ui_tool_jam main.cpp)
include_directories(/usr/local/include/gtk-3.0)
include_directories(/usr/local/include/gtk-2.0)
include_directories(/usr/local/include/glib-2.0)
include_directories(/usr/local/include/glib-2.0/include/glibconfig.h)
