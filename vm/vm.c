#include <stddef.h>
#include <string.h>
#include "vm.h"

#include <stdio.h>

static void *const *vm_var_list = NULL;
static int vm_var_list_size = 0;

int vm_init(void *const var_list[], const int var_list_size) {
    if (vm_var_list != NULL) {
        printf("var_list already initialized\n");
        return -1;
    }
    if (var_list == NULL || var_list_size <= 0) {
        printf("Invalid var_list or var_list_size\n");
        return -1;
    }
    vm_var_list = var_list;
    vm_var_list_size = var_list_size;
    printf("VM initialized with %d variables\n", vm_var_list_size);
    return 0;
}

int vm_deinit(void) {
    if (vm_var_list == NULL) {
        printf("var_list not initialized\n");
        return -1;
    }
    vm_var_list = NULL;
    vm_var_list_size = 0;
    return 0;
}

int vm_get_var_list_size(void) {
    if(vm_var_list == NULL) {
        printf("var_list not initialized\n");
        return -1;
    }
    return vm_var_list_size;
}