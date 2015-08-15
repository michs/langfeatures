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

#define LOGGING_EXT
#include "logging.h"

#ifndef USE_LOG4C
#pragma GCC diagnostic ignored "-Wempty-body"
// #pragma GCC diagnostic ignored "-Werror"
#endif

/* ------------------------------------------------------------------------- */
#ifdef USE_LOG4C

static log4c_category_t *root;
static int log4c_initialized;

void
log_init(int world_rank)
{
    if ( log4c_initialized != 0 )
        return;

    log4c_init();

    log4c_appender_t* myappender;
    char fname[256];

    sprintf(fname, "applog_%05d", world_rank);
    myappender = log4c_appender_get(fname);
    log4c_appender_set_type(myappender, &log4c_appender_type_stream);

    root = log4c_category_get ("root");
    sprintf(fname, "%05d", world_rank);
    GlobLogCat = log4c_category_get (fname);
    if ( GlobLogCat == NULL )
        GlobLogCat = root;
    log4c_category_set_appender(GlobLogCat, myappender);
    log4c_category_debug(GlobLogCat,
                         "log_init(): Initialization done.\n");
    log4c_initialized = 1;
}


void
log_fini( void )
{
    if ( log4c_initialized != 0 )
    {
        log4c_fini();
        log4c_initialized = 0;
    }
}

#else // USE_LOG4C

int _module_logging_; // Just to have something in this module for
                      // the release configuration

#endif // USE_LOG4C
/* ------------------------------------------------------------------------- */

#ifndef USE_LOG4C
#pragma GCC diagnostic pop
#endif
