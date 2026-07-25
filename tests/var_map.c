#include "var_map.h"
#include "vm.h"
#include "var_list.h"

ADD_INT(VAR_ID_TEST_VAR, VAR_INDEX_TEST_VAR, 10, 5, 100, 1, "teste")

void *const var_list[VAR_INDEX_COUNT] = {
    [VAR_INDEX_TEST_VAR] = ADD_VAR_VALUE(VAR_ID_TEST_VAR),
};

int var_list_size = sizeof(var_list) / sizeof(var_list[0]);