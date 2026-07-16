add_executable(test_vm test_vm.c var_map.c)
add_library(unity unity/unity.c)

target_include_directories(test_vm PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CMAKE_CURRENT_SOURCE_DIR}/unity
)

target_link_libraries(test_vm PRIVATE vm)
target_link_libraries(test_vm PRIVATE unity)

target_compile_options(test_vm PRIVATE -Wall -Wextra)

add_test(NAME test_vm COMMAND test_vm)