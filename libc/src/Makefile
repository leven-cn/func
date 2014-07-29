# Makefile

-include $(TOPDIR)/def.mk

SUBDIR_CTYPE = ctype

.PHONY: all clean test
	
all:
	$(MAKE) -C $(SUBDIR_CTYPE) -e TOPDIR=../$(TOPDIR)
	@echo $(SUBDIR_CTYPE) Build done

clean:
	$(MAKE) -C $(SUBDIR_CTYPE) clean
	@echo $(SUBDIR_CTYPE) Clean done
	
test:
	$(MAKE) -C $(SUBDIR_CTYPE) test
	@echo $(SUBDIR_CTYPE) Test done
