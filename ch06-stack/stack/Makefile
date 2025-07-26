OBJS = stack.o teststack.o

test: $(OBJS)
	gcc -Wall -o test $(OBJS)

stack.o: stack.c
teststack.o: teststack.c
clean:
	rm -f $(OBJS) test