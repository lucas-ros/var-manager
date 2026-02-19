#include <stdio.h>

#include "../vm.h"
#include "var_list.h"
#include "var_map.h"

int main() {
    vm_init(var_list, var_list_size);
    int test = 0;
    if (vm_get(var_name_test_var, &test) == 0) {
        printf("test_var value: %d\n", test);
    } else {
        printf("test_var not found\n");
    }
    return 0;
}