

.PHONY: all first \
	    log4c_unpack log4c_make log4_install \
	    cunit_unpack cunit_make cunit_install

CUNIT_VER = 2.1-2
LOG4C_VER = 1.2.2

first :
	@echo "==========================================="
	@echo "                  Usage"
	@echo "==========================================="
	@echo "-------------------------------------------"
	@echo "Use one of the following targets:"
	@echo "-------------------------------------------"
	@echo "    all"
	@echo "    log4c_make log4_install"
	@echo "    cunit_make cunit_install"
	@echo "==========================================="

all :  log4c_install cunit_install

log4c_unpack :
	rm -rf log4-$(LOG4C_VER)
	tar xvzf log4c-$(LOG4C_VER).tar.gz

log4c_make :
	if [ ! -d log4c-$(LOG4C_VER) ] ; then make log4c_unpack ; fi ;\
	cd log4c-$(LOG4C_VER) ; \
	./configure --prefix=$(DEVLIBS) ; \
	make

log4c_install : log4c_make
	cd log4c-$(LOG4C_VER) ; \
	make install


cunit_unpack :
	rm -rf CUnit-$(CUNIT_VER)
	tar xvjf CUnit-$(CUNIT_VER)-src.tar.bz2

cunit_make :
	if [ ! -d CUnit-$(CUNIT_VER) ] ; then make cunit_unpack ; fi ;\
	cd CUnit-$(CUNIT_VER) ; \
	if [ -f Makefile ] ; then make distclean ; fi ;\
	./configure --prefix=$(DEVLIBS) ; \
	make

cunit_install : cunit_make
	cd CUnit-$(CUNIT_VER); \
	make install
