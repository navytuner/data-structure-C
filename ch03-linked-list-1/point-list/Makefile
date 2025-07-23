CC = gcc
CFLAGS = -Wall

OBJS = main.o point.o arraylist.o

main: $(OBJS)
	$(CC) $(CFLAGS) -o main $(OBJS)

main.o: main.c point.h arraylist.h
point.o: point.c point.h
arraylist.o: arraylist.c arraylist.h

clean:
	rm -r *.o main