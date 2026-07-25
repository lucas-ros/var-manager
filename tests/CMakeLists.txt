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

option(VM_TEST_LOGS "Enable var-manager logs in unit tests" OFF)

if(VM_TEST_LOGS)
    target_compile_definitions(test_vm PRIVATE VM_TEST_LOGS=1)
endif()