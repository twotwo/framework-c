#include <stdio.h>
#include <string.h>
#include <CUnit/CUnit.h>


/* +: add +/- before digital
 * -: fill blank with on right
 * 0: fill with 0
 * *: 下一个参数是字符数
 */
void test_flag_int(void) {
	char string[15];
	sprintf(string, "%+d", 22);
	CU_ASSERT(0 == strncmp(string, "+22", 3));

	sprintf(string, "%+9d", 22);
	CU_ASSERT(0 == strncmp(string, "      +22", 9));

	sprintf(string, "%+-9d", 22);
	CU_ASSERT(0 == strncmp(string, "+22      ", 9));

	sprintf(string, "%+09d", 22);
	CU_ASSERT(0 == strncmp(string, "+00000022", 9));

	sprintf(string, "%+*d",9, 22);
	CU_ASSERT(0 == strncmp(string, "      +22", 9));

}

/* +: add +/- before digital
 * -: fill blank with on right
 * 0: fill with 0
 *
 * .: left is string size, right is size ofter point
 */
void test_flag_float(void) {
	char string[15];
	int len;
	
	len = sprintf(string, "%9.2f", 22.0);
	CU_ASSERT_EQUAL(len, 9);
	CU_ASSERT(0 == strncmp(string, "    22.00", 9));

	sprintf(string, "%+9.2f", 22.0);
	CU_ASSERT(0 == strncmp(string, "   +22.00", 9));

}

void test_flag_string(void) {
	char string[15];
	char *STR = "hello, world"; // length =12
	int len;

	//%10s -  min size is 10, don't sub long string
	len = sprintf(string, "%10s", STR);
	CU_ASSERT_EQUAL(len, 12);
	CU_ASSERT(0 == strncmp(string, STR, 12));

	//%.10s -  sub long string
	len = sprintf(string, "%.10s", STR);
	CU_ASSERT_EQUAL(len, 10);
	CU_ASSERT(0 == strncmp(string, "hello, wor", 10));

	//%14s - fill blank at left
	len = sprintf(string, "%14s", "hello, world");
	CU_ASSERT_EQUAL(len, 14);
	CU_ASSERT(0 == strncmp(string, "  hello, world", 14));

	//%-14s - fill blank at right
	len = sprintf(string, "%-14s", "hello, world");
	CU_ASSERT_EQUAL(len, 14);
	CU_ASSERT(0 == strncmp(string, "hello, world  ", 14));

	//%14.10s -  all is 14, char size is 10
	len = sprintf(string, "%14.10s", "hello, world");
	CU_ASSERT_EQUAL(len, 14);
	CU_ASSERT(0 == strncmp(string, "    hello, wor", 14));

	//%-14.10s -  fill at right
	len = sprintf(string, "%-14.10s", "hello, world");
	CU_ASSERT_EQUAL(len, 14);
	CU_ASSERT(0 == strncmp(string, "hello, wor    ", 14));

}

void test_hlL_type(void) {
	char string[15];

	//hh	char %256
	sprintf(string, "%hhd %hhd", (char)278, (char)'a');
	CU_ASSERT(0 == strncmp(string, "22 97", 5));
	//h	short %65536
	sprintf(string, "%hd %hd", (short)65558, (short)'a');
	CU_ASSERT(0 == strncmp(string, "22 97", 5));
	//l	long
	//ll	long long
	//L	long double
}

void test_type(void) {
	char string[15];
	// 278 = 100(256)+16(22)
	sprintf(string, "%X", 278);
	CU_ASSERT(0 == strncmp(string, "116", 3));

	int len, num;
	len = sprintf(string, "%X%n", 278, &num);
	CU_ASSERT(0 == strncmp(string, "116", 3));
	CU_ASSERT_EQUAL(len, 3);
	CU_ASSERT_EQUAL(num, 3);
}


int init_suite_sprintf(void) {
	return 0;
}

int clean_suite_sprintf(void) {
	return 0;
}
