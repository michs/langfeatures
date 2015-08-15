#
# Main makefile of the project
#
#


-include ../make_init.mk


ARTEFACT = $(MK_CONFIG)/<artefact>

# Define default target before including more definitions.
all : $(ARTEFACT)


-include ../make_proj.mk

INSTALL_DIR ?= $(HOME)/devel/usr

# Artefacts
#
# Build a library
#$(ARTEFACT) : $(OBJS)
#	ar -ruc $(ARTEFACT) $(OBJS)

# Build an executable
#$(ARTEFACT) : $(REF_LIBS) $(OBJS)
#        $(MPICXX) $(LDFLAGS) $(LDFLAGS_OS) $(LDFLAGS_USER) -o "$(ARTEFACT)" $(SPEC_OBJS) $(OBJS) $(REF_LIBS) $(EXT_LIBS)

# Clean targets
#
#.PHONY : projclean refclean
#
#clean : projclean refclean
#
#refclean :
#	( cd ../app ; make clean )
#
#projclean :
#	rm -f $(C_OBJS) $(CPP_OBJS) $(C_DEPS) $(CPP_DEPS) $(ARTEFACT)


# Referenced projects
#
#../app/$(MK_CONFIG)/mdbase.a ::
#	( cd ../app ; make $(MK_CONFIG)/mdbase.a )

