CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
TESTS = -DTEST_DIVIDE -DTEST_INTERLEAVE -DTEST_SHUFFLE
GCC = gcc $(CFLAGS) $(TESTS)
EXEC = hw7
OBJS =  shuffle.o main.o
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

$(EXEC): $(OBJS) shuffle.h
	$(GCC) $(OBJS) -o $(EXEC)

test: $(EXEC)
	./$(EXEC) 4 | sort > output4
	./$(EXEC) 11 | sort > output11
	./$(EXEC) 8 | sort > output8

memory: $(EXEC)
	$(VALGRIND) --log-file=log1 ./$(EXEC) 4
	$(VALGRIND) --log-file=log2 ./$(EXEC) 11
	$(VALGRIND) --log-file=log3 ./$(EXEC) 8

%.o : %.c
	$(GCC) -c $<

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f output4 output 11 output8 log1 log2 log3