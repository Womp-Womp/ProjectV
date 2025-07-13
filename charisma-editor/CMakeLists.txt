cmake_minimum_required(VERSION 3.10)
project(CharismaEditor)

# Find the Qt6 package
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Add source files
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(charisma-editor ${SOURCES})

# Link to Qt6
target_link_libraries(charisma-editor PRIVATE Qt6::Widgets)

# Add include directories
target_include_directories(charisma-editor PUBLIC src)

# Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(unit_tests tests/test_project_manager.cpp src/project_manager.cpp)
target_link_libraries(unit_tests GTest::gtest_main pthread Qt6::Core)
target_include_directories(unit_tests PUBLIC src)
