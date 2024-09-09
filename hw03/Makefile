CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror --DTEST_INTEGRATE -DRUN_INTEGRATE
GCC = gcc $(CFLAGS)
LIBS = -lm
EXEC = hw3



all: hw2a hw2b

#Build hw2 using integrate1, and all five functions
#Creates 5 different executables, because of the dependences
hw2a: hw2-func1-1 hw2-func2-1 hw2-func3-1 hw2-func4-1 hw2-func5-1


#Build hw2 using integrate2, and all five functions
#Creates 5 different executables, because of the dependences
hw2b: hw2-func1-2 hw2-func2-2 hw2-func3-2 hw2-func4-2 hw2-func5-2


#build each of the executables for integrate1
hw2-func1-1: hw2a.o integrator.o func1.o
	$(GCC) hw2a.o integrator.o func1.o -o hw2-func1-1

hw2-func2-1: hw2a.o integrator.o func2.o
	$(GCC) hw2a.o integrator.o func2.o -o hw2-func2-1

hw2-func3-1: hw2a.o integrator.o func3.o
	$(GCC) hw2a.o integrator.o func3.o -o hw2-func3-1

hw2-func4-1: hw2a.o integrator.o func4.o
	$(GCC) hw2a.o integrator.o func4.o -o hw2-func4-1 -lm

hw2-func5-1: hw2a.o integrator.o func5.o
	$(GCC) hw2a.o integrator.o func5.o -o hw2-func5-1 -lm

#build each of the executables for integrate2
hw2-func1-2: hw2b.o integrator.o func1.o
	$(GCC) hw2b.o integrator.o func1.o -o hw2-func1-2

hw2-func2-2: hw2b.o integrator.o func2.o
	$(GCC) hw2b.o integrator.o func2.o -o hw2-func2-2

hw2-func3-2: hw2b.o integrator.o func3.o
	$(GCC) hw2b.o integrator.o func3.o -o hw2-func3-2

hw2-func4-2: hw2b.o integrator.o func4.o
	$(GCC) hw2b.o integrator.o func4.o -o hw2-func4-2 -lm

hw2-func5-2: hw2b.o integrator.o func5.o
	$(GCC) hw2b.o integrator.o func5.o -o hw2-func5-2 -lm

#build hw2 with integrate1
hw3.o: hw3.c hw3.h
	$(GCC) -c hw3.c -o hw3.o

#compile answer3
answer3.o: answer3.c hw3.h
	$(GCC) -c answer3.c

#compile func1
func1.o: func1.c
	$(GCC) -c func1.c

#compile func2
func2.o: func2.c
	$(GCC) -c func2.c

#compile func3
func3.o: func3.c
	$(GCC) -c func3.c

#compile func4
func4.o: func4.c
	$(GCC) -c func4.c

#compile func5
func5.o: func5.c
	$(GCC) -c func5.c


clean:
	/bin/rm -f input*
	/bin/rm -f *.o
	/bin/rm -f testgen 
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f hw3 hw3.prof
	/bin/rm -f -r testdir

