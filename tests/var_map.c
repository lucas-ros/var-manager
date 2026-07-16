#include "var_map.h"
#include "vm.h"
#include "var_list.h"

ADD_INT(var_name_test_var, 10, 5, 100, 1, "teste")

void *const var_list[] = {
    ADD_VAR_VALUE(var_name_test_var),
};

int var_list_size = sizeof(var_list) / sizeof(var_list[0]);