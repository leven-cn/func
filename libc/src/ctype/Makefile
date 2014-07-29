# Makefile for ctype

-include $(TOPDIR)/def.mk

CPPFLAGS += -I$(TOPDIR)/include

PROG = test_ctype.exe

SRCS = $(notdir $(wildcard *.c))
OBJS = $(subst .c,.o,$(SRCS))

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY: all clean test
	
all: $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $(PROG) $^
	@echo Build ctype done

clean:
	-$(RM) $(PROG) $(OBJS)
	@echo Clean ctype done
	
test:
	chmod u+x $(PROG)
	./$(PROG)
