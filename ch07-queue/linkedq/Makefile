OBJS = linkedq.o test_linkedq.o

test: $(OBJS)
	gcc -Wall -o test $(OBJS)

linkedq.o: linkedq.c
test_linkedq.o: test_linkedq.c
clean:
	rm -f $(OBJS) test