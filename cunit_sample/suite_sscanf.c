#include <stdio.h>
#include <string.h>
#include <CUnit/CUnit.h>


void test_scanf_skip(void) {
	int num;
	sscanf("123 456", "%*d %d", &num);
	CU_ASSERT_EQUAL(456, num);
}

void test_scanf_digital(void) {
	int num;
	sscanf("0x16", "%i", &num);
	CU_ASSERT_EQUAL(22, num);
}

void test_parse_url(void) {
	const char *s = "http://www.baidu.com:80";
    char protocol[32] = { 0 };
    char host[128] = { 0 };
    char port[8] = { 0 };
    sscanf(s,"%[^:]://%[^:]:%[1-9]",protocol,host,port);
    CU_ASSERT_STRING_EQUAL("http", protocol);
}

void test_parse_gps(void) {
	const char *s = "$GPRMC,121252.000,A,3958.3032,N,11629.6046,E,15.15,359.95,070306,,,A*54 ";

	char utc_time[11];
	char status;
	float latitude_value;
	char latitude;
	float longtitude_value;
	char longtitude;
	float speed;
	float azimuth_angle;
	char utc_data[11];

	//%*[^,]: skip until ,
    sscanf(s,"%*[^,],%[^,],%c,%f,%c,%f,%c,%f,%f,%[^,]",
            utc_time, &status,\
            &latitude_value, &latitude,\
            &longtitude_value, &longtitude, &speed,\
            &azimuth_angle, utc_data);

    CU_ASSERT_STRING_EQUAL("121252.000", utc_time);
    CU_ASSERT_DOUBLE_EQUAL(3958.3032, latitude_value, 1);
}
