#CFLAGS = -Wall -Werror -Wextra
SOURCE = $(wildcard s21_*.c)
OS=$(shell uname)
#SANIT = -g3 -fsanitize=address
QMAKE = /home/felekc/Qt/6.4.2/gcc_64/bin/qmake
ifeq ($(OS), Linux)
  LIBS=-lcheck -lpthread -lrt -lm -lsubunit
else
  LIBS=-lcheck
endif

all: test lcov install

p.o: p.c
	gcc -c p.c

test: p.o 
	gcc $(SANIT) --coverage tests.c p.c $(LIBS) $(CFLAGS)
	./a.out

gcov_report:
	rm -rf a-p.gcda a-p.gcno
	gcovr --html --html-details -o report.html
	
check:
	cp ../materials/linters/.clang-format ./
	clang-format -i *.c
	clang-format -i *.h
	clang-format -n *.c
	clang-format -n *.h
	rm -f .clang-format

clean:
	rm -rf *.o *.a *.gcno *.gcda *.info *.out *.html *.css
	rm -rf ./lcov_report
	rm -rf *.info *.gcno *.gcda a.out report
	rm -rf .qmake.stash untitled.app ui_* *.o moc_* Makefile_qt Manual
	rm -rf ./back/*.o ./back/*.out
	rm -rf  Archive.tar.gz

lcov:
	lcov --capture --directory ./ --output-file coverage.info
	genhtml coverage.info --output-directory ./lcov_report

install:
	$(QMAKE) ./calcul.pro -o Makefile_qt
	make -f Makefile_qt
	make clean
	rm -rf ../bild
	mkdir ../bild
	mv -f calcul ../bild/

dist: clean
	tar -czf Archive.tar.gz ../src

uninstall: clean
	rm -rf ../bild

dvi:
	open man.md


