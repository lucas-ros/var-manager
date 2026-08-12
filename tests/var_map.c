#include "var_map.h"
#include "vm.h"
#include "var_list.h"

ADD_INT(VAR_ID_TEST_INT, VAR_STD_TEST_INT, VAR_MIN_TEST_INT, VAR_MAX_TEST_INT, 1, VAR_DESCRIPTION_TEST_INT)

void *const var_list[VAR_INDEX_COUNT] = {
    [VAR_INDEX_TEST_INT] = ADD_VAR_VALUE(VAR_ID_TEST_INT),
};

int var_list_size = sizeof(var_list) / sizeof(var_list[0]);