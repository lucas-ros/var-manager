#include <stdio.h>

#include "../vm.h"
#include "var_list.h"
#include "var_map.h"


int main() {
    printf("test_var min value: %d\n", var_name_test_var_param.value_cfg.min_value);
    printf("test_var std value: %d\n", vm_var_name_test_var.param->value_cfg.std_value);
    return 0;
}