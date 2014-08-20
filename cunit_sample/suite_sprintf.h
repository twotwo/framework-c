#include <stdio.h>
#include <CUnit/CUnit.h>

void test_flag_int(void);

void test_flag_float(void);

void test_flag_string(void);

void test_hlL_type(void);

void test_type(void);

int init_suite_sprintf(void);

int clean_suite_sprintf(void);

/**
 * Suite for sprintf
 * 
 */
CU_TestInfo suite_sprintf[] = {
	{"case_flag_int", test_flag_int},
	{"case_flag_float", test_flag_float},
	{"case_flag_string", test_flag_string},
	{"case_hlL", test_hlL_type},
	{"case_type", test_type},
	CU_TEST_INFO_NULL
};
