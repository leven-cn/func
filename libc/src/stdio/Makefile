# Makefile for stdio

-include $(TOPDIR)/def.mk

CPPFLAGS += -I$(TOPDIR)/include

PROG = test_stdio.exe

SRCS = $(notdir $(wildcard *.c))
OBJS = $(subst .c,.o,$(SRCS))

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY: all clean test
	
all: $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $(PROG) $^
	@echo Build stdio done

clean:
	-$(RM) $(PROG) $(OBJS)
	@echo Clean stdio done
	
test:
	chmod u+x $(PROG)
	./$(PROG)
	@echo Test stdio done
