BUILD_DIR = build

all: test

test:
	mkdir -p $(BUILD_DIR)
	cmake ./ -B $(BUILD_DIR)
	$(MAKE) -C $(BUILD_DIR) tests
	./build/tests

gcov:
	mkdir -p $(BUILD_DIR)
	cmake -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=Debug .
	$(MAKE) -C $(BUILD_DIR) tests
	./build/tests
	$(MAKE) calc_coverage

clang:
	clang-format -n test/*.cc containers/* containers_plus/*

valgrind:
	valgrind --leak-check=full ./build/tests

clean:
	@rm -rf $(BUILD_DIR)

.PHONY: all test clang valgrind clean
