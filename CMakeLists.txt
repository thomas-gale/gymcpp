cmake_minimum_required(VERSION 3.17)

project(GymCpp
    VERSION 0.1
    DESCRIPTION "C++ OpenAI Gym inspired communication library"
    LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 17)

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(test)

# Gymclient library 
# Gymserver library