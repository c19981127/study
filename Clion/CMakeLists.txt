cmake_minimum_required(VERSION 3.15)
project(Clion)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++0x ")

link_libraries(glfw3 GL m Xrandr Xi Xxf86vm pthread dl Xinerama Xcursor X11)
add_executable(Clion main.cpp)

