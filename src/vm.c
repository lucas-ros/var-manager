#include <stddef.h>
#include <string.h>
#include "vm.h"

#include <stdio.h>

static void *const *vm_var_list;
static int vm_var_list_size = 0;

int vm_init(void *const var_list[], const int var_list_size) {
    if (var_list == NULL || var_list_size <= 0) {
        printf("Invalid var_list or var_list_size\n");
        return -1;
    }
    vm_var_list = var_list;
    vm_var_list_size = var_list_size;
    printf("VM initialized with %d variables\n", vm_var_list_size);
    return 0;
}

int vm_get(const var_name_t name, void *const get_value) {
    if (vm_var_list == NULL || vm_var_list_size == 0) {
        printf("VM not initialized\n");
        return -1;
    }

    for (int i = 0; i < vm_var_list_size; i++) {
        struct var_param *param = NULL;
        memcpy(&param, vm_var_list[i], sizeof(struct var_param*));
        printf("Checking variable with name %d\n", param->name);
        if (param->name == name) {
            switch (param->type) {
                case VAR_TYPE_INT:
                    if (*(int *)get_value == ((struct int_var *)vm_var_list[i])->cur_value) {
                        printf("Value for variable %d is already %d\n", name, *(int *)get_value);
                        return 0;
                    }
                    if (*(int *)get_value < ((struct int_var *)vm_var_list[i])->value_cfg.min_value ||
                     *(int *)get_value > ((struct int_var *)vm_var_list[i])->value_cfg.max_value) {
                        printf("Value for variable %d is out of range (%d - %d)\n", name, ((struct int_var *)vm_var_list[i])->value_cfg.min_value, ((struct int_var *)vm_var_list[i])->value_cfg.max_value);
                        return -1;
                    }
                    *(int *)get_value = ((struct int_var *)vm_var_list[i])->cur_value;
                    printf("Value for variable %d retrieved: %d\n", name, *(int *)get_value);
                    return 0;
                default:
                    printf("Unsupported variable type for variable %d\n", name);
                    return -1;
            }
        }
    }
    printf("Variable with name %d not found\n", name);
    return -1;
}
