cmake_minimum_required(VERSION 3.16)
project(var_manager C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(app
    app/app.c
    vm.c
)

target_include_directories(app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_options(app PRIVATE -Wall -Wextra)
