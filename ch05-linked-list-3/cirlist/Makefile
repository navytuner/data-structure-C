OBJS = testcirlist.o cirlist.o
test: $(OBJS) 
	gcc -Wall -o test $(OBJS) 
cirlist.o: cirlist.c
testcirlist.o: testcirlist.c
clean:
	rm -f $(OBJS) test