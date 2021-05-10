cmake_minimum_required(VERSION 3.10)
project(X_Athena_Widgets_Demo C)

set(CMAKE_C_STANDARD 11)

find_package (PkgConfig REQUIRED)
pkg_check_modules (XAW7 REQUIRED xaw7)

include_directories (${XAW7_INCLUDE_DIRS})
link_directories (${XAW7_LIBRARY_DIRS})

add_executable(X_Athena_Widgets_Demo main.c)
add_definitions (${XAW7_CFLAGS_OTHER})
target_link_libraries (X_Athena_Widgets_Demo ${XAW7_LIBRARIES})
