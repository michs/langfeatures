#!/bin/bash

# The build environment is currently suported for GNU and Intel compilers.
#
#
# The following variables are expected to be defined in order to build
# the project. Define the variables below and source the file in your shell.
#
# CPP           Invocation of the C preprocessor
#
# CC            Invocation of the C compiler
# CC_NAME       Short name of the C compiler: (1)
# CC_VERSION    Version number of the C compiler
#
# CXX           Invocation of the C++ compiler
# CXX_NAME      Short name of the C++ compiler: (1)
# CXX_VERSION   Version number of the C++ compiler
#
# F90           Invocation of the Fortran 90 compiler
# F77           Invocation of the Fortran 77 compiler
#
# FC            Invocation of the Fortran compiler
# FC_NAME       Short name of the Fortran compiler: (1)
# FC_VERSION    Version number of the Fortran compiler
#
# DEVLIBS       Path for installations of external libraries used
#               in the project
#               Typically, $DEVLIBS/bin must be added to PATH,
#               $DEVLIBS/lib must be added to LD_LIBRARY_PATH resp.
#               DYLD_LIBRARY_PATH
#
# (1) One of: gnu intel
#

# --------------------------------------------------------------------------
# For convenience, below are definitions prepared for gnu and intel compilers,
# which are maybe sufficient.

# Define some variables:
#
# Place for external libraries used in the project
# PRIV_USR_PATH=$MICHS_USR
#
# Used compiler and its version:
# COMPILER=   # predefined: gnu, intel
# VERS=       # version of the compiler (f.ex. "5" for current GNU 5, or
              # "15.0" for current Intel

if [ "$COMPILER" == "gnu" ] ; then
    if [ -z "$PRIV_USR_PATH" ] ; then
        echo "Please define environment variable 'PRIV_USR_PATH'"
    fi
    if [ -z "$VERS" ] ; then
        echo "Please define environment variable 'VERS'"
    fi
    export CPP="gcc-mp-$VERS -E"

    export CC=gcc-mp-$VERS
    export CC_NAME=gcc
    export CC_VERSION=$VERS

    export CXX=g++-mp-$VERS
    export CXX_NAME=gcc
    export CXX_VERSION=$VERS

    export F90=gfortran-mp-$VERS
    export F77=gfortran-mp-$VERS

    export FC=gfortran-mp-$VERS
    export FC_NAME=gcc
    export FC_VERSION=$VERS

    PREDEF_EXTERNAL=1

elif [ "$COMPILER" == "intel" ] ; then
    if [ -z "$PRIV_USR_PATH" ] ; then
        echo "Please define environment variable 'PRIV_USR_PATH'"
    fi
    if [ -z "$VERS" ] ; then
        echo "Please define environment variable 'VERS'"
    fi
    export CPP="icc -E"

    export CC=icc
    export CC_NAME=$COMPILER
    export CC_VERSION=$VERS

    export CXX=icpc
    export CXX_NAME=$COMPILER
    export CXX_VERSION=$VERS

    export F90=ifort
    export F77=ifort

    export FC=ifort
    export FC_NAME=$COMPILER
    export FC_VERSION=$VERS

    PREDEF_EXTERNAL=1
fi

if [ "$PREDEF_EXTERNAL" == "1" ] ; then
    # External libraries used in the project
    export DEVLIBS=$PRIV_USR_PATH/$CC_NAME/$VERS

    # Path to the bin
    export PATH=$PRIV_USR_PATH/$CC_NAME/$VERS/bin:$PATH
    export LD_LIBRARY_PATH=$PRIV_USR_PATH/$CC_NAME/$VERS/lib:$LD_LIBRARY_PATH
    export DYLD_LIBRARY_PATH=$PRIV_USR_PATH/$CC_NAME/$VERS/lib:$DYLD_LIBRARY_PATH

fi
