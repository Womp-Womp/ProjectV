cmake_minimum_required(VERSION 3.10)
project(CharismaEditor)

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(charisma-editor ${SOURCES})

# Add include directories
target_include_directories(charisma-editor PUBLIC src)
