cmake_minimum_required(VERSION 3.10)
project(CharismaEngine)

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(charisma-engine ${SOURCES})

# Add include directories
target_include_directories(charisma-engine PUBLIC src)
