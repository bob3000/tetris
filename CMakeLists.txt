cmake_minimum_required(VERSION 3.0)
project(
  tetris
  VERSION 0.1
  DESCRIPTION "This is tetris"
  LANGUAGES C
)

set(CMAKE_C_STANDARD 99)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Adding Raylib
include(FetchContent)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES OFF CACHE BOOL "" FORCE) # don't build the supplied example games
fetchcontent_declare(raylib GIT_REPOSITORY https://github.com/raysan5/raylib.git GIT_TAG master)
fetchcontent_makeavailable(raylib)

add_subdirectory(src)
add_subdirectory(apps)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  include(CTest)
  add_subdirectory(tests)
endif()
