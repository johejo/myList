CC = gcc
PROGRAM=myList
CFLAGS = -Wall -O
OBJS = main.o list.o
$(PROGRAM) : $(OBJS)
	$(CC) $(OBJS) -o $(PROGRAM)
main.o : main.c defs.h
	$(CC) -c $(CFLAGS) main.c

list.o : list.c defs.h
	$(CC) -c $(CFLAGS) list.c

clean:
	-rm -rf $(PROGRAM)* $(OBJS) $(PROGRAM)