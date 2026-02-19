ADD_INT(var_name_test_var, 10, 5, 100)

void *const var_list[] = {
    ADD_VAR_VALUE(var_name_test_var),
};

int var_list_size = sizeof(var_list) / sizeof(var_list[0]);