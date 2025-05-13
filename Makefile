CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror -Wextra
PKGCONFIG = $(shell which pkg-config)
TEST_FLAGS = $(shell $(PKGCONFIG) --libs gtest)
TEST_TARGET = s21_test

# Путь к исходным файлам
SRC_DIR = s21_containers
TESTS_SRC_DIR = tests

# Получение имен подкаталогов в директории SRC_DIR
SUBDIRS := $(shell find $(SRC_DIR) -type d)

# Получение списка исходных файлов
SRCS := $(foreach dir,$(SUBDIRS),$(wildcard $(dir)/*.cc))
TESTS_SRCS = $(wildcard $(TESTS_SRC_DIR)/*.cc)

all: test gcov_report

test: $(TESTS_SRCS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TESTS_SRCS) $(TEST_FLAGS)
	./$(TEST_TARGET)
 
gcov_report: CXXFLAGS += --coverage
gcov_report: $(TESTS_SRCS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $? $(TEST_FLAGS)
	./$(TEST_TARGET) > /dev/null
	lcov -o $(TEST_TARGET).info -c -d . --ignore-errors mismatch --no-external --rc lcov_branch_coverage=1
	genhtml -o report/ $(TEST_TARGET).info --rc lcov_branch_coverage=1
	open report/index.html

clean:
	rm -f $(TEST_TARGET)
	rm -f *.gc* *.info
	rm -rf report/
