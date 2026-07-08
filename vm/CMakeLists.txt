add_library(vm STATIC vm.c)
target_include_directories(vm PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include/
)
target_compile_options(vm PRIVATE -Wall -Wextra)
target_compile_definitions(vm PRIVATE $<$<CONFIG:Debug>:DEBUG_MODE>)