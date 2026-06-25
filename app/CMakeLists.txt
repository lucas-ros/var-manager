add_executable(app app.c)
target_link_libraries(app PRIVATE vm)
target_compile_options(app PRIVATE -Wall -Wextra)