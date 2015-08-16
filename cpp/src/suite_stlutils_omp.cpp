
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

#include "cunit_main.h"
#include "logging.h"

#include <tuple>
#include <string>
#include <iostream>
/* -------------------------------------------------------------------------
 *
 * Suite name : STL utilities using OpenMP
 *
 *
 * ------------------------------------------------------------------------- */

// Forward declarations of tests.
DECL_TESTFUNC(tuple_omp);


// Definition of the test suite
CU_TestInfo tests_stl_utils_omp[] = {
    CU_TESTINFO(tuple_omp),
    CU_TEST_INFO_NULL
};

/* ------------------------------------------------------------------------- */
/* Suite management */

int init_suite_stl_utils_omp( void )
{
    return 0;
}

int cleanup_suite_stl_utils_omp( void )
{
    return 0;
}

/* ------------------------------------------------------------------------- */
/* Test implementations */

#define NUM_TASKS 100  // choose an even number

#define I_VAL  2
#define HELLO_STR "Hello, world."
#define BYE_STR   "Good bye"

typedef struct
{
    int  iValue;
    int *iValue_p;

} TaskInfo;

/*
 * TaskInfo *     Always the same for all tasks
 * std::string *  Pool of pre-allocated data
 * int            Variating value
 */
typedef std::tuple<TaskInfo *, std::string *, int> CompTask;


namespace comp_task
{

int sum;

int num_hello, num_bye;

void task_func(CompTask task)
{
    TaskInfo    *tInfo;
    std::string *str;
    int          i;

    std::tie(tInfo, str, i) = task;

    CU_ASSERT( tInfo->iValue == I_VAL );
    CU_ASSERT( *tInfo->iValue_p == I_VAL*I_VAL );

    if ( *str == std::string(HELLO_STR) )
        #pragma omp critical
        num_hello += 1;
    else if ( *str == std::string(BYE_STR) )
        #pragma omp critical
        num_bye += 1;
    else
        CU_FAIL("We do not talk correctly with each other");

    #pragma omp critical (par_sum)
    sum += i;
}

} // end namespace comp_task

// using namespace comp_task;

DECL_TESTFUNC(tuple_omp)
{
    L4C(__log4c_category_trace(GlobLogCat, "tuple_omp() -- begin"));

    TaskInfo tInfo = { I_VAL, new int(I_VAL*I_VAL) };
    std::string str[2];

    str[0] = HELLO_STR;
    str[1] = BYE_STR;

    #pragma omp parallel
    {
        #pragma omp single nowait
        {
            for (int i = 1; i <= NUM_TASKS; i++)
            {
                CompTask t = std::make_tuple(&tInfo, &str[i%2], i);

                #pragma omp task firstprivate(tInfo)
                comp_task::task_func(t);
            }
        }
    }
    CU_ASSERT( comp_task::num_hello == NUM_TASKS/2);
    CU_ASSERT( comp_task::num_bye == NUM_TASKS/2 );

    CU_ASSERT( comp_task::sum == NUM_TASKS*(NUM_TASKS+1)/2 );
                                    // in case Gauss was right

    L4C(__log4c_category_trace(GlobLogCat, "tuple_omp() -- end"));
}
