CC = gcc
CFLAGS = -Wall
OBJS = main.o namecard.o arraylist.o

main: $(OBJS)
	$(CC) $(CFLAGS) -o main $(OBJS)

main.o: main.c namecard.h arraylist.h
namecard.o: namecard.h namecard.c 
arraylist.o: arraylist.h arraylist.c

clean:
	rm -f $(OBJS) main