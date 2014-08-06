# Makefile

-include ../def.mk

TOPDIR = .
SRCDIR = $(TOPDIR)/src
INCDIR = $(TOPDIR)/include

vpath %.c $(SRCDIR)
vpath %.h $(INCDIR)

.PHONY: all clean test
	
all:
	$(MAKE) -C $(SRCDIR) -e TOPDIR=../$(TOPDIR)
	@echo Build done

clean:
	$(MAKE) -C $(SRCDIR) clean
	@echo Clean done
	
test:
	$(MAKE) -C $(SRCDIR) test
	@echo Test done
