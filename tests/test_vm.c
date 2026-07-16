#include "unity.h"
#include "vm.h"
#include "var_map.h"

void setUp(void) {}
void tearDown(void) {
    vm_deinit();
}

void test_vm_init_valid(void) {
    int result = vm_init(var_list, var_list_size);
    TEST_ASSERT_EQUAL(0, result);
}

void test_vm_deinit_valid(void) {
    if(vm_init(var_list, var_list_size) < 0) {
        TEST_FAIL();
    }
    int result = vm_deinit();
    TEST_ASSERT_EQUAL(0, result);
}

void test_vm_init_var_list_null(void) {
    int result = vm_init(NULL, var_list_size);
    TEST_ASSERT_EQUAL(-1, result);
}

void test_vm_init_var_size_zero(void) {
    int result = vm_init(var_list, 0);
    TEST_ASSERT_EQUAL(-1, result);
}

void test_vm_deinit_invalid(void) {
    int result = vm_deinit();
    TEST_ASSERT_EQUAL(-1, result);
}

void test_vm_init_already_initialized_var_list(void) {
    vm_init(var_list, var_list_size);
    int result = vm_init(var_list, var_list_size);
    TEST_ASSERT_EQUAL(-1, result);
}

void test_vm_get_var_list_size_valid(void) {
    if(vm_init(var_list, var_list_size) < 0) {
        TEST_FAIL();
    }
    int result = vm_get_var_list_size();
    TEST_ASSERT_EQUAL(var_list_size, result);
}

void test_vm_get_var_list_size_invalid(void) {
    int result = vm_get_var_list_size();
    TEST_ASSERT_EQUAL(-1, result);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_vm_init_valid);
    RUN_TEST(test_vm_deinit_valid);
    RUN_TEST(test_vm_init_var_list_null);
    RUN_TEST(test_vm_init_var_size_zero);
    RUN_TEST(test_vm_deinit_invalid);
    RUN_TEST(test_vm_init_already_initialized_var_list);
    RUN_TEST(test_vm_get_var_list_size_valid);
    RUN_TEST(test_vm_get_var_list_size_invalid);

    return UNITY_END();
}
