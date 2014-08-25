#include "suite_sprintf.h"
#include "suite_sscanf.h"
#include "build/build_info.h"

#include <stdlib.h>
#include <CUnit/Basic.h>
#include <CUnit/Automated.h>
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
   showVersion();

   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add all suite to the registry */
   if(CUE_SUCCESS != CU_register_suites(suites))
   {
      exit(EXIT_FAILURE);
   }

   /* Basic(CU_BRM_SILENT), only show case running status */
   CU_basic_set_mode(CU_BRM_SILENT);
   CU_basic_run_tests();

   /* Automated */
   CU_set_output_filename("build/report/CU_Report");
   CU_list_tests_to_file();
   CU_automated_run_tests();

   CU_cleanup_registry();
   return CU_get_error();
}