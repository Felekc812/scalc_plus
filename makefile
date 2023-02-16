CPP = g++ -std=c++17 -lstdc++
#CFLAGS = -Wall -Werror -Wextra
COV_FALGS= -fprofile-arcs -ftest-coverage
#SANIT = -g3 -fsanitize=address

OS=$(shell uname)

ifeq ($(OS), Linux)
	OPEN = xdg-open
	LIBS= -lgtest -lpthread -pthread -lrt -lm 
	LEAKS= valgrind --track-origins=yes --leak-check=full  ./test
else
	OPEN = open
	LIBS=-lcheck -lgtest -pthread
endif

all: clean test 

test:
	@$(CPP) $(SANIT) $(CFLAGS)  gtest.cpp $(LIBS) $(GTEST) -o test
	@./test

gcov_report: clean
	-mkdir report
	$(CPP) $(COV_FALGS) s21_matrix_oop.cpp test.cpp $(LIBS) $(GTEST) -o test
	./test
	gcov test_gcov
	lcov -t "matrix_oop" -o matrix_oop.info -c -d .
	genhtml -o report matrix_oop.info
	$(OPEN) ./report/index.html


clean:
	@rm -rf *.o *.so *.a *.gc* *.info report *.out *.so *.info test
	@rm -rf report
