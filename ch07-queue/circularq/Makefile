OBJS = circularq.o test_circularq.o

test: $(OBJS)
	gcc -Wall -o test $(OBJS)

circularq.o: circularq.c
test_circularq.o: test_circularq.c

clean:
	rm -f $(OBJS) test