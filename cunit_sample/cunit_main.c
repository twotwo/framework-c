#include "suite_sprintf.h"
#include "suite_sscanf.h"

#include <stdlib.h>
#include <CUnit/Basic.h>
#include <CUnit/Console.h>

CU_SuiteInfo suites[] = {
   {"suite_sprintf", init_suite_sprintf, clean_suite_sprintf, suite_sprintf},
   {"suite_sscanf", init_suite_sprintf, clean_suite_sprintf, suite_sscanf},
   CU_SUITE_INFO_NULL
};

/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main()
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add all suite to the registry */
   if(CUE_SUCCESS != CU_register_suites(suites))
   {
      exit(EXIT_FAILURE);
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}