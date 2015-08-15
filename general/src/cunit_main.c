/*
 * langfeatures - Examples and tests for programming languages and tools.
 *  Copyright (C) 2015  Michael Schliephake
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "cunit_main.h"

#include <stdio.h>

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "logging.h"


int cunit_main( int argc, char *argv[],  CU_SuiteInfo *suites)
{
    log_init(0);

    CU_initialize_registry();
    CU_register_suites(suites);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    CU_cleanup_registry();

    log_fini();

    return 0;
}
