cmake_minimum_required(VERSION 3.1)
project(myproj)

# (See more info on 'find_package' and exactly what it does in cmakes online documentation.
#  Link: https://cmake.org/cmake/help/latest/command/find_package.html)
# Finds and loads settings from SDL2 and OpenGL projects
find_package(SDL2 REQUIRED)
#find_package(OpenGL REQUIRED)
# SDL2 header files are visible and SDL2 can be used for all targets
# In this directoy and all subdirectories. To only make SDL2 available
# to specific targets, use 'target_incude_directories' instead.
#include_directories(${SDL2_INCLUDE_DIRS})

# List here all header files that users of this target (if it's a library) needs to access
# (To be specific the files listed here is what will appear in /usr/include or /usr/local/include 
# or something else of this sort when a user build and cmake-installs this repository)
#target_include_directories(mytarget
#    PUBLIC
#       ../include
#)

# Generates debug symbols for when we debug with gdb
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(thirdparty_src/glad)
add_subdirectory(thirdparty_src/imgui)
add_subdirectory(src)
