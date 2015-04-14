CC=g++
#CFLAGS= -g -Wall -Werror

all: prog

prog: numtri.cpp
	$(CC) $(CFLAGS) -o  prog numtri.cpp