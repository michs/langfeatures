# Yet another option for custimisation.
#
# CFLAGS += ...
CPP_FLAGS += -std=c++11

ifeq ($(CXX_NAME),gnu)
    CPP_FLAGS += -fopenmp -Wno-write-strings
    LDFLAGS += -fopenmp

else ifeq ($(CXX_NAME),intel)
    CPP_FLAGS += -qopenmp
    LDFLAGS += -qopenmp

endif

# Specifikation of C modules.
#
# C_MODULES += \
# <module-name> \

# Specification of C++ modules.
#
CPP_MODULES += \
suite_stlutils \
suite_stlutils_omp \
test_cpp

# Specifikation of module-specific options.
#
# <module-name>_CFLAGS =
# suite_stlutils_CPPFLAGS = -Wno-write-strings

# Referenced projects that must be built before the own built.
#
REF_PROJECTS += \
../general
#
REF_LIBS += \
../general/$(MK_CONFIG)/libgeneral.a

# Additional libraries for linking
#
EXT_LIBS += \
-lcunit

ifeq ($(CXX_NAME),intel)

EXT_LIBS += \
-lc++

endif
