# Makefile for coreutils

-include $(TOPDIR)/../def.mk

PROG = pwd.exe

SRCS = $(notdir $(wildcard *.c))
OBJS = $(subst .c,.o,$(SRCS))
DEPS =
LOGS = $(notdir $(wildcard *.log))
DIFF = $(notdir $(wildcard *.diff))

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY: all clean test
	
all: $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $(PROG) $^ $(DEPS)
	@echo Build $(PROG) done

clean:
	-$(RM) $(PROG) $(OBJS) $(LOGS) $(DIFF)
	@echo Clean $(PROG) done
	
test:
	chmod u+x $(PROG)
	
	# Test pwd
	./pwd.exe > test.log
	pwd > std.log
	./pwd.exe -L >> test.log
	pwd -L >> std.log
	./pwd.exe -P >> test.log
	pwd -P >> std.log
	
	diff test.log std.log > test.diff
	-$(RM) $(LOGS)
	@echo Test $(PROG) done
