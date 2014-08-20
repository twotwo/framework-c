#include <stdio.h>
#include <CUnit/CUnit.h>

void test_scanf_skip(void);

void test_scanf_digital(void);

void test_parse_url(void);

void test_parse_gps(void);

/**
 * Suite for sprintf
 * 
 */
CU_TestInfo suite_sscanf[] = {
	{"case_scanf_skip", test_scanf_skip},
	{"case_scanf_digital", test_scanf_digital},
	{"case_parse_url", test_parse_url},
	{"case_parse_gps", test_parse_gps},
	CU_TEST_INFO_NULL
};
