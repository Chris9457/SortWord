cmake_minimum_required(VERSION 3.0)

project(SortUtils)

set(PUBLIC_DIR public)
set(SOURCE_DIR src)

file(GLOB_RECURSE PUBLIC_FILES ${PUBLIC_DIR}/*)
file(GLOB_RECURSE SOURCE_FILES ${SOURCE_DIR}/*)

add_library(${PROJECT_NAME} STATIC ${PUBLIC_FILES} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} 
		                   PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/${PUBLIC_DIR})
