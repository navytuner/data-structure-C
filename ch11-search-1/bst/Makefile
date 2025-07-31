OBJS = bst.o testbst.o

test: $(OBJS)
	gcc -Wall -o test $(OBJS)

%.o: %.c
	gcc -Wall -c -o $@ $<

clean:
	rm -f $(OBJS) test