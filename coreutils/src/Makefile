# Makefile for coreutils

-include $(TOPDIR)/../def.mk

SRCS = $(notdir $(wildcard *.c))
PROG = $(subst .c,.exe,$(SRCS))
LOGS = $(notdir $(wildcard *.log))
DIFF = $(notdir $(wildcard *.diff))

%.exe : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: all clean test
	
all: $(PROG)
	@echo Build $(PROG) done

clean:
	-$(RM) $(PROG) $(LOGS) $(DIFF)
	@echo Clean $(PROG) done
	
test:
	chmod u+x $(PROG)
	
	./pwd.exe > test.log
	pwd > std.log
	./pwd.exe -L >> test.log
	pwd -L >> std.log
	./pwd.exe -P >> test.log
	pwd -P >> std.log
	
	diff test.log std.log > test.diff
	-$(RM) $(LOGS)
	@echo Test $(PROG) done
