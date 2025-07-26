OBJS = in2post.o stack.o postcal.o testcal.o 
CC = gcc
CFLAGS = -Wall -g -gdwarf-4

test: $(OBJS)
	$(CC) $(CFLAGS) -o test $(OBJS)
clean:
	rm -f $(OBJS) test
