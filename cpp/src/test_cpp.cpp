

#include <stdio.h>

#include "cunit_main.h"

/* Define test suites */
#define SUITE_DEFINITION(name)          \
extern CU_TestInfo tests_ ## name [];    \
extern int init_suite_ ## name (void);   \
extern int cleanup_suite_ ## name (void);

SUITE_DEFINITION(stl_utils)


/* Prepare test collection for runner */
CU_SuiteInfo mpi_suites[] = {
    { "STL Utilities",
      init_suite_stl_utils, cleanup_suite_stl_utils, tests_stl_utils
    },
    CU_SUITE_INFO_NULL
};


int main( int argc, char *argv[] )
{
    return cunit_main(argc, argv, mpi_suites);
}
