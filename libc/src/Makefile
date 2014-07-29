# Makefile

-include $(TOPDIR)/def.mk

SUBDIR_CTYPE = ctype
SUBDIR_STR = string

.PHONY: all clean test
	
all:
	$(MAKE) -C $(SUBDIR_CTYPE) -e TOPDIR=../$(TOPDIR)
	$(MAKE) -C $(SUBDIR_STR) -e TOPDIR=../$(TOPDIR)

clean:
	$(MAKE) -C $(SUBDIR_CTYPE) clean
	$(MAKE) -C $(SUBDIR_STR) clean
	
test:
	$(MAKE) -C $(SUBDIR_CTYPE) test
	$(MAKE) -C $(SUBDIR_STR) test
