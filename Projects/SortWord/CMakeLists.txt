cmake_minimum_required(VERSION 3.0)

project(SortWordApp)

set(SOURCE_DIR src)
file(GLOB_RECURSE SOURCE_FILES ${SOURCE_DIR}/*)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
