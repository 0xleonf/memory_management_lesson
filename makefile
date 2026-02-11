CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -c

TEST_DIR = tests
SRC_DIR = src
MUNIT_DIR = munit

test_enum.o: $(TEST_DIR)/test_enum.c
	$(CC) $(CFLAGS) $< -o $@

enum.o: $(SRC_DIR)/enum.c
	$(CC) $(CFLAGS) $< -o $@

munit.o: $(MUNIT_DIR)/munit.c
	$(CC) $(CFLAGS) $< -o $@

test_enum: munit.o enum.o test_enum.o
	$(CC) *.o -o test_enum

clean:
	rm -f *.o 
	rm -f test_enum

.PHONY: all clean 

