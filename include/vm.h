#ifndef VM_H
#define VM_H

#include <stdint.h>
#include <stdarg.h>

typedef void (*vm_log_fn_t)(const char *fmt, va_list args);

#define ADD_INT(name_, std_value_, min_value_, max_value_, persist_, description_) \
    static const struct var_param name_##_param = { \
        .name = name_, \
        .type = VAR_TYPE_INT, \
        .persist = persist_, \
        .description = description_,\
    }; \
    static const struct int_var_value_cfg vm_##name_##_cfg = { \
        .std_value = (int)std_value_, \
        .min_value = (int)min_value_, \
        .max_value = (int)max_value_, \
    }; \
    static struct int_var vm_##name_ = { \
        .param = &name_##_param, \
        .value_cfg = &vm_##name_##_cfg, \
        .cur_value = std_value_\
    }; \

#define ADD_VAR_VALUE(name_) (void*)&vm_##name_

typedef uint16_t var_name_t;

enum var_type {
    VAR_TYPE_INT,
};

struct int_var_value_cfg {
    const int std_value;
    const int min_value;
    const int max_value;
};

struct var_param {
    const var_name_t name;
    const enum var_type type;
    const char persist;
    const char *description;
};

struct int_var {
    const struct var_param *const param;
    const struct int_var_value_cfg *const value_cfg;
    int cur_value;
};

void vm_log_set_callback(vm_log_fn_t fn);
int vm_init(void *const var_list[], const int var_list_size);
int vm_deinit(void);
int vm_get_var_list_size(void);
int vm_get(const var_name_t name, void *const get_value);

#endif // VM_H