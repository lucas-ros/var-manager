#include "unity.h"
#include "vm.h"
#include "var_map.h"

void setUp(void) {}
void tearDown(void) {}

void test_compilation(void) {
    TEST_ASSERT_EQUAL(1, 1);
}

void test_vm_init_valid(void) {
    int result = vm_init(var_list, var_list_size);
    TEST_ASSERT_EQUAL(0, result);
}

void test_vm_init_var_list_null(void) {
    int result = vm_init(NULL, var_list_size);
    TEST_ASSERT_EQUAL(-1, result);
}

void test_vm_init_var_size_zero(void) {
    int result = vm_init(NULL, var_list_size);
    TEST_ASSERT_EQUAL(-1, result);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_vm_init_valid);
    RUN_TEST(test_vm_init_var_list_null);
    RUN_TEST(test_vm_init_var_size_zero);

    return UNITY_END();
}
