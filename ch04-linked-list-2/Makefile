CC = gcc
CFLAGS = -Wall
OBJS = testlist.o linkedlist.o

testlist: $(OBJS)
	$(CC) $(CFLAGS) -o testlist $(OBJS)

testlist.o: testlist.c 
linkedlist.o: linkedlist.c

clean:
	rm -f $(OBJS) testlist