file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/*.c")
set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/")

add_library(libtetris)
target_sources(libtetris PRIVATE ${PROJECT_SOURCES})
target_include_directories(libtetris PRIVATE ${PROJECT_INCLUDE})
target_link_libraries(libtetris PUBLIC raylib)
target_compile_definitions(libtetris PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/../assets/") # Set the asset path macro to the absolute path on the dev machine
