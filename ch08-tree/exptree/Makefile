OBJS = in2post.o exptree.o main.o

main: $(OBJS)
	gcc -Wall -o main $(OBJS)

%.o: %.c
	gcc -Wall -c -o $@ $<

clean:
	rm -f $(OBJS) main
