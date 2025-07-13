cmake_minimum_required(VERSION 3.10)
project(CharismaEngine)

# Find SFML
find_package(SFML 2.6 REQUIRED system window graphics network audio)

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(charisma-engine ${SOURCES})

# Link to SFML
target_link_libraries(charisma-engine PRIVATE sfml-graphics sfml-window sfml-system)

# Add include directories
target_include_directories(charisma-engine PUBLIC src)
