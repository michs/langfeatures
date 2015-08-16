# Yet another option for custimisation.
#
# CFLAGS += ...
CPP_FLAGS += -std=c++11 -Wno-write-strings

# Specifikation of C modules.
#
# C_MODULES += \
# <module-name> \

# Specification of C++ modules.
#
CPP_MODULES += \
suite_stlutils \
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
-lcunit \
-lc++
