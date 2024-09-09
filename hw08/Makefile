CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
TESTS = -DTEST_DIVIDE -DTEST_INTERLEAVE -DTEST_SHUFFLE
GCC = gcc $(CFLAGS) $(TESTS)
EXEC = hw8
OBJS =  shuffle.o main.o
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

$(EXEC): $(OBJS) shuffle.h
	$(GCC) $(OBJS) -o $(EXEC)

all: $(EXEC)

test: $(EXEC)
	./$(EXEC) 3 1 | sort > output1
	diff -w output1 expected/expected_3_1
	./$(EXEC) 3 2 | sort > output2
	diff -w output2 expected/expected_3_2
	./$(EXEC) 4 2 | sort > output3
	diff -w output3 expected/expected_4_2
	./$(EXEC) 6 2 | sort > output4
	diff -w output4 expected/expected_6_2

memory: $(EXEC)
	$(VALGRIND) --log-file=log1 ./$(EXEC) _3_1
	$(VALGRIND) --log-file=log2 ./$(EXEC) _3_2
	$(VALGRIND) --log-file=log3 ./$(EXEC) _4_2
	$(VALGRIND) --log-file=log4 ./$(EXEC) _6_2

%.o : %.c
	$(GCC) -c $<

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f output1 output2 output3 output4 log1 log2 log3 log4
