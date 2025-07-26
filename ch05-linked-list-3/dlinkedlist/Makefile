OBJS = dlinkedlist.o test_dlinkedlist.o

test: dlinkedlist.o test_dlinkedlist.o
	gcc -Wall -o test $(OBJS)

dlinkedlist.o: dlinkedlist.c
test_dlinkedlist.o: test_dlinkedlist.c
clean:
	rm -f $(OBJS) test