# Variables used in the makefiles
CC=gcc
CFLAGS=-I. -v
DEPS = llist.h # Put in your .h files here


# Compile a .c file into an object file for linking.  The object file is
# the machine code the compiler spits out that corresponds to everything in the .c file.
# You can combine .o files together into libraries too (not shown)
# 
# $(DEPS) is there because if any header file changes you need to recompile the objects.
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

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

