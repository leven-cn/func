# Makefile

-include ../def.mk

TOPDIR = .
SRCDIR = $(TOPDIR)/src

vpath %.c $(SRCDIR)

.PHONY: all clean test
	
all:
	$(MAKE) -C $(SRCDIR) -e TOPDIR=../$(TOPDIR)
	@echo Build done

clean:
	$(MAKE) -C $(SRCDIR) clean -e TOPDIR=../$(TOPDIR)
	@echo Clean done
	
test:
	$(MAKE) -C $(SRCDIR) test -e TOPDIR=../$(TOPDIR)
	@echo Test done
