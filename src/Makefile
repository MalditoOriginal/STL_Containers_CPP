CC = g++
CFLAGS = -c -Wall -Werror -Wextra -g -std=c++17
TEST_CFLAGS = -lgtest -lgmock -pthread
OBJ = $(CFILES:.cc=.o)
TESTS_OBJ = $(TESTS_CFILES:.cc=.o)
TESTS_CFILES = $(wildcard tests/*.cc)
CFILES = $(wildcard *.cc)
OBJ_MAIN = tests/test_main.cc


all: clean test

%.o : %.cc
	$(CC) $(CFLAGS) $^ -o $@

test : $(TESTS_OBJ)
	$(CC) $^ -o test $(TEST_CFLAGS)
	./test

leaks : $(TESTS_OBJ)
	$(CC) $^ -o test $(TEST_CFLAGS)
	./test
	leaks --atExit -- ./test

gcov_report: clean
	$(CC) --coverage $(TESTS_CFILES) -o test $(TEST_CFLAGS)
	./test
	lcov --ignore-errors mismatch -t "test" -o test.info --no-external -c -d .
	genhtml -o report/ test.info
	open ./report/index.html

checkstyle:
	clang-format -style=google -n tests/*.cc
	clang-format -style=google -n tests/*.h
	clang-format -style=google -n array/*.tpp
	clang-format -style=google -n array/*.h
	clang-format -style=google -n AVLtree/*.h
	clang-format -style=google -n *.h
	clang-format -style=google -n list/*.tpp
	clang-format -style=google -n list/*.h
	clang-format -style=google -n map/*.h
	clang-format -style=google -n multiset/*.h
	clang-format -style=google -n set/*.h
	clang-format -style=google -n vector/*.tpp
	clang-format -style=google -n vector/*.h
	clang-format -style=google -n queue/*.h
	clang-format -style=google -n stack/*.h

styling:
	clang-format -style=google -i tests/*.cc
	clang-format -style=google -i tests/*.h
	clang-format -style=google -i array/*.tpp
	clang-format -style=google -i array/*.h
	clang-format -style=google -i AVLtree/*.h
	clang-format -style=google -i *.h
	clang-format -style=google -i list/*.tpp
	clang-format -style=google -i list/*.h
	clang-format -style=google -i map/*.h
	clang-format -style=google -i multiset/*.h
	clang-format -style=google -i set/*.h
	clang-format -style=google -i vector/*.tpp
	clang-format -style=google -i vector/*.h
	clang-format -style=google -i queue/*.h
	clang-format -style=google -i stack/*.h

clean:
	rm -rf $(OBJ) $(TESTS_OBJ) test *.gcov *.gcno *.gcda *.info report $(EXECUTABLE)