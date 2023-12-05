CC=gcc
CFLAGS=-I. -v
DEPS = llist.h # Put in your .h files here


# Compile a .c file into an object file for linking
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: tictactoe test_llist

tictactoe: tictactoe.o llist.o
	$(CC) -o tictactoe tictactoe.o llist.o

test_llist: llist.o test_llist.o
	$(CC) -o test_llist test_llist.o llist.o

clean-ux:	
	# Unix style clean target
	rm -f *.o *~ tictactoe test_llist

clean:
	# DOS style clean target
	del *.o *.exe

