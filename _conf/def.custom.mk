# User's customisations of the general build.
#

ifeq ($(OS),Darwin)
  ifeq ($(CXX_NAME),intel)
    CPP_FLAGS += -stdlib=libc++
  endif
endif

# CFLAGS_USER +=
MPICFLAGS_USER += -DMPI_ALLOWED=1

# CPPFLAGS_USER +=
MPICPPFLAGS_USER += -DMPI_ALLOWED=1

ifdef DEBUG

CFLAGS_USER += -DUSE_LOG4C
CPPFLAGS_USER += -DUSE_LOG4C

LDFLAGS_USER += -llog4c
MPILDFLAGS_USER += -llog4c

endif
