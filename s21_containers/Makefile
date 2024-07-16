CC = gcc
CPPFLAGS = -Wall -Werror -Wextra -std=c++17 -lstdc++

OBJ_MAIN = tests/test_main.cc
OBJ_STACK = tests/stack_test.cc
OBJ_QUEUE = tests/queue_test.cc
OBJ_LIST = tests/list_test.cc
OBJ_MAP = tests/map_test.cc
OBJ_SET = tests/set_test.cc
OBJ_VECTOR = tests/vector_test.cc
OBJ_TEST = $(OBJ_STACK) $(OBJ_QUEUE) $(OBJ_VECTOR) $(OBJ_LIST) $(OBJ_MAP) $(OBJ_SET) $(OBJ_MAIN)


UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
  	OPEN_CMD = xdg-open
	LEAKS_CMD = valgrind --tool=memcheck --leak-check=yes
	ADD_LIB = -lgtest -lpthread
endif

ifeq ($(UNAME_S),Darwin)
	OPEN_CMD = open -a "Google Chrome"
	LEAKS_CMD = leaks -atExit --
	ADD_LIB = -lgtest
endif

all: test

test: clean
	@$(CC) $(CPPFLAGS) $(OBJ_TEST) -o test $(ADD_LIB)
	@./test

test_leaks: clean
	@$(CC) $(CPPFLAGS) $(OBJ_TEST) -o test $(ADD_LIB)
	$(LEAKS_CMD) ./test

gcov: clean
	@$(CC) $(CPPFLAGS) --coverage  $(OBJ_STACK) $(OBJ_QUEUE) $(OBJ_VECTOR) $(OBJ_LIST) $(OBJ_MAP) $(OBJ_SET) $(OBJ_MAIN) -o test $(ADD_LIB)
	@./test
	@rm -rf test_main.gcda test_main.gcno
	@lcov -t "s21_containers_test" -o fizzbuzz.info -c -d . --ignore-errors mismatch
	@genhtml -o report fizzbuzz.info
	@$(OPEN_CMD) report/index.html

style:
	@find . -name "*.h" -o -name "*.cc" | xargs clang-format -style=Google -i

clean:
	@-rm -rf *.o *.gcno *.gcda *.info *.gcov *.a *.dSYM report test

.PHONY:	all test test_leaks gcov style clean


