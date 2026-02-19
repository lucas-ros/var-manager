#include <stdint.h>

#define ADD_INT(name_, std_value_, min_value_, max_value_) \
    static const struct var_param name_##_param = { \
        .name = name_, \
        .type = VAR_TYPE_INT, \
    }; \
    static struct int_var vm_##name_ = { \
        .param = &name_##_param, \
        .value_cfg = { \
            .std_value = (const int)std_value_, \
            .min_value = (const int)min_value_, \
            .max_value = (const int)max_value_, \
        }, \
    };

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
};

struct int_var {
    const struct var_param *const param;
    const struct int_var_value_cfg value_cfg;
    int cur_value;
};

int vm_get(const var_name_t name, void *const get_value);
int vm_init(void *const var_list[], const int var_list_size);