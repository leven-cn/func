# Makefile for stdlib

-include $(TOPDIR)/def.mk

CPPFLAGS += -I$(TOPDIR)/include

PROG = test_stdlib.exe

SRCS = $(notdir $(wildcard *.c))
OBJS = $(subst .c,.o,$(SRCS))
DEPS = $(TOPDIR)/src/string/strlen.o $(TOPDIR)/src/string/strcmp.o \
		$(TOPDIR)/src/string/strncmp.o

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY: all clean test
	
all: $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $(PROG) $^ $(DEPS)
	@echo Build stdlib done

clean:
	-$(RM) $(PROG) $(OBJS)
	@echo Clean stdlib done
	
test:
	chmod u+x $(PROG)
	./$(PROG)
	@echo Test stdlib done
