# Variables used in the makefiles
CC=gcc
#CFLAGS=-I. -v
CFLAGS=-I.
DEPS = llist.h # Put in your .h files here


# Compile a .c file into an object file for linking.  The object file is
# the machine code the compiler spits out that corresponds to everything in the .c file.
# You can combine .o files together into libraries too (not shown)
# 
# $(DEPS) is there because if any header file changes you need to recompile the objects.
# % means this a pattern matching rule.
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 

# The above rule with patterns is a shortcut for the following rules
#tictactoe.o : tictactoe.c llist.h
#	gcc -c  -I. -v -o tictactoe.o tictactoe.c
#llist.o : llist.c llist.h
#	gcc -c  -I. -v -o llist.o llist.c

# This is the default target. If you just type "make" it will run all of these
# dependencies.
all: tictactoe test_llist

# to compile the tictactoe binary, you need the main tictactoe code and the llist library
tictactoe: tictactoe.o llist.o  
	$(CC) -o tictactoe tictactoe.o llist.o


# Unit test program for the llist library
test_llist: llist.o test_llist.o
	$(CC) -o test_llist test_llist.o llist.o

# clean targets are used to get rid of generated files
clean-sh:	
	# Unix shell style clean target
	rm -f *.o *~ tictactoe test_llist

clean:
	# DOS style clean target
	delete *.o *.exe

