CC = gcc
OBJS = testbt.o binarytree.o
CFLAGS = -Wall

test: $(OBJS)
	$(CC) $(CFLAGS) -o test $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) test