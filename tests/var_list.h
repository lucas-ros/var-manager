#ifndef VAR_LIST_H
#define VAR_LIST_H

#define VAR_ID_TEST_INT UINT32_C(0x0101)

#define VAR_STD_TEST_INT 10
#define VAR_MIN_TEST_INT 5
#define VAR_MAX_TEST_INT 100
#define VAR_DESCRIPTION_TEST_INT "test_description_int"

enum var_index_list {
    VAR_INDEX_TEST_INT,
    VAR_INDEX_COUNT,
};

#endif // VAR_LIST_H