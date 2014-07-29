# Makefile Definitions

## Built-In Commands
SHELL = /bin/bash
CC = gcc
#CXX = g++
#MAKE = make
#RM = rm -f

## C Compiler Options
CDEBUG := -g -O2
CFLAGS := $(CDEBUG) -std=c99
CFLAGS += -Wall -Wextra
#CXXFLAGS := $(CDEBUG)
CPPFLAGS := -I.
LDFLAGS := -L.