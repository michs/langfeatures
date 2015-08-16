

#include <stdio.h>

#include "cunit_main.h"

/* Define test suites */
#define SUITE_DEFINITION(name)          \
extern CU_TestInfo tests_ ## name [];    \
extern int init_suite_ ## name (void);   \
extern int cleanup_suite_ ## name (void);

SUITE_DEFINITION(stl_utils)
SUITE_DEFINITION(stl_utils_omp)


/* Prepare test collection for runner */
CU_SuiteInfo mpi_suites[] = {
    { "STL Utilities",
      init_suite_stl_utils, cleanup_suite_stl_utils, tests_stl_utils
    },
    { "STL Utilities OpenMP",
      init_suite_stl_utils_omp, cleanup_suite_stl_utils_omp, tests_stl_utils_omp
    },
    CU_SUITE_INFO_NULL
};


int main( int argc, char *argv[] )
{
    return cunit_main(argc, argv, mpi_suites);
}
