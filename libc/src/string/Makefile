# Makefile for string

-include $(TOPDIR)/../def.mk

CPPFLAGS += -I$(TOPDIR)/include

PROG = test_string.exe

SRCS = $(notdir $(wildcard *.c))
OBJS = $(subst .c,.o,$(SRCS))

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY: all clean test
	
all: $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $(PROG) $^
	@echo Build string done

clean:
	-$(RM) $(PROG) $(OBJS)
	@echo Clean string done
	
test:
	chmod u+x $(PROG)
	./$(PROG)
	@echo Test string done
