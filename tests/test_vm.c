#include "unity.h"
#include "vm.h"
#include "var_map.h"
#include "var_list.h"

#include <stdio.h>
#include <stdarg.h>

#if defined(VM_TEST_LOGS)
static void log_stdout(const char *fmt, va_list args) {
    vprintf(fmt, args);
}
#endif

void setUp(void) {
#if defined(VM_TEST_LOGS)
    vm_log_set_callback(log_stdout);
#else
    vm_log_set_callback(NULL);
#endif
}

void tearDown(void) {
    vm_log_set_callback(NULL);
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

void test_vm_get_by_id_int(void) {
    if(vm_init(var_list, var_list_size) < 0) {
        TEST_FAIL();
    }
    int get_buffer = 0;
    vm_get_by_id(VAR_ID_TEST_INT, &get_buffer);
    TEST_ASSERT_EQUAL(VAR_STD_TEST_INT, get_buffer);
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
    RUN_TEST(test_vm_get_by_id_int);

    return UNITY_END();
}
