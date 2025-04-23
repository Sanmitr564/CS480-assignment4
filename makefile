#Makefile

# Specify compiler
CC = gcc
# -std=c++11  C/C++ variant to use, e.g. C++ 2011
# -Wall       show the necessary warning files
# -g3         include information for symbolic debugger e.g. gdb 
CCFLAGS = -std=gnu99 -Wall -g3 -c

# object files
OBJS = main.o

# Program name
PROGRAM = pagingwithwsclock

# The program depends upon its object files
$(PROGRAM) : $(OBJS)
	$(CC) -o $(PROGRAM) $(OBJS)

main.o : main.c 
	$(CC) $(CCFLAGS) main.c

# Once things work, people frequently delete their object files.
# If you use "make clean", this will do it for you.
# As we use gnuemacs which leaves auto save files termintating
# with ~, we will delete those as well.
clean :
	rm -f $(OBJS) *~ $(PROGRAM)

