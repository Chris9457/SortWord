cmake_minimum_required(VERSION 3.0)

project(SortWord)

set(SOURCE_DIR src)
file(GLOB_RECURSE SOURCE_FILES ${SOURCE_DIR}/*)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE SortUtils)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)