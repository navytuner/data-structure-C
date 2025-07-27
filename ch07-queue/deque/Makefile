OBJS = deque.o testdq.o
CC = gcc
CFLAGS = -Wall

test: $(OBJS)
	gcc -Wall -o test $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) test