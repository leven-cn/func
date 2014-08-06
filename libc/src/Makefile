# Makefile

-include $(TOPDIR)/../def.mk

SUBDIR_CTYPE = ctype
SUBDIR_STR = string
SUBDIR_STDLIB = stdlib
SUBDIR_STDIO = stdio

.PHONY: all clean test
	
all:
	$(MAKE) -C $(SUBDIR_CTYPE) -e TOPDIR=../$(TOPDIR)
	$(MAKE) -C $(SUBDIR_STR) -e TOPDIR=../$(TOPDIR)
	$(MAKE) -C $(SUBDIR_STDLIB) -e TOPDIR=../$(TOPDIR)
	$(MAKE) -C $(SUBDIR_STDIO) -e TOPDIR=../$(TOPDIR)

clean:
	$(MAKE) -C $(SUBDIR_CTYPE) clean
	$(MAKE) -C $(SUBDIR_STR) clean
	$(MAKE) -C $(SUBDIR_STDLIB) clean
	$(MAKE) -C $(SUBDIR_STDIO) clean
	
test:
	$(MAKE) -C $(SUBDIR_CTYPE) test
	$(MAKE) -C $(SUBDIR_STR) test
	$(MAKE) -C $(SUBDIR_STDLIB) test
	$(MAKE) -C $(SUBDIR_STDIO) test
