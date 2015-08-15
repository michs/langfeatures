
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

#include "cunit_main.h"
#include "logging.h"

#include <tuple>
#include <iostream>
/* -------------------------------------------------------------------------
 *
 * Suite name : STL utilities
 *
 *
 * ------------------------------------------------------------------------- */

// Forward declarations of tests.
DECL_TESTFUNC(tuple);


// Definition of the test suite
CU_TestInfo tests_stl_utils[] = {
    CU_TESTINFO(tuple),
    CU_TEST_INFO_NULL
};

/* ------------------------------------------------------------------------- */
/* Suite management */

int init_suite_stl_utils( void )
{
    return 0;
}

int cleanup_suite_stl_utils( void )
{
    return 0;
}

/* ------------------------------------------------------------------------- */
/* Test implementations */

DECL_TESTFUNC(tuple)
{
    L4C(__log4c_category_trace(GlobLogCat, "tuple() -- begin"));

    int i = 1;
    std::tuple<int, char, double> t1(i, 'A', 3.14159);

    char str[] = "Hello, world";

    std::tuple<int *, char *, double *> t2(new int(1),
                                           str, new double(3.14159));

    int ii, *p_ii;
    char cc, *p_cc;
    double dd, *p_dd;

    std::tie(ii, cc, dd) = t1;


    std::cout << "ii: " << ii << std::endl;
    CU_ASSERT( ii == 1 );
    CU_ASSERT( cc == 'A' );
    CU_ASSERT( dd == 3.14159 );

    std::tie(p_ii, p_cc, p_dd) = t2;
    CU_ASSERT( *p_ii == 1 );
    CU_ASSERT( p_cc == str );
    CU_ASSERT( *p_dd == 3.14159 );

    L4C(__log4c_category_trace(GlobLogCat, "tuple() -- end"));
}
