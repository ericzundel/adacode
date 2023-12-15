# Variables used in the makefiles
CC=gcc
CFLAGS=-I. -v
DEPS = list.h # Put in your .h files here


# Compile a .c file into an object file for linking.  The object file is
# the machine code the compiler spits out that corresponds to everything in the .c file.
# You can combine .o files together into libraries too (not shown)
# 
# $(DEPS) is there because if any header file changes you need to recompile the objects.
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# This is the default target. If you just type "make" it will run all of these
# dependencies.
all:  handle_example


#  test program for the list library
handle_example: handle_example.o list.o
	$(CC) -o handle_example list.o handle_example.o

# clean targets are used to get rid of generated files
clean-sh:	
	# Unix shell style clean target
	rm -f *.o *~ handle_example

clean:
	# DOS style clean target
	del *.o *.exe
