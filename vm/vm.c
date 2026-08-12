#include <stddef.h>
#include <string.h>
#include "vm.h"

#include <stdarg.h>

static vm_log_fn_t log_callback = NULL;
static void *const *vm_var_list = NULL;
static int vm_var_list_size = 0;

void vm_log_set_callback(vm_log_fn_t fn) {
    log_callback = fn;
}

static void vm_log(const char *fmt, ...) {
    if (log_callback) {
        va_list args;
        va_start(args, fmt);
        log_callback(fmt, args);
        va_end(args);
    }
}

int vm_init(void *const var_list[], const int var_list_size) {
    if (vm_var_list != NULL) {
        vm_log("var_list already initialized\n");
        return -1;
    }
    if (var_list == NULL || var_list_size <= 0) {
        vm_log("Invalid var_list or var_list_size\n");
        return -1;
    }
    vm_var_list = var_list;
    vm_var_list_size = var_list_size;
    vm_log("VM initialized with %d variables\n", vm_var_list_size);
    return 0;
}

int vm_deinit(void) {
    if (vm_var_list == NULL) {
        vm_log("var_list not deinitialized\n");
        return -1;
    }
    vm_var_list = NULL;
    vm_var_list_size = 0;
    vm_log("var_list deinitialized\n");
    return 0;
}

int vm_get_var_list_size(void) {
    if(vm_var_list == NULL) {
        vm_log("var_list not initialized\n");
        return -1;
    }
    return vm_var_list_size;
}

int vm_get_by_id(const var_id_t id, void *const get_value) {
    return -1;
}