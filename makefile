CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -c

TEST_DIR = tests
SRC_DIR = src
MUNIT_DIR = munit

# Enumeration
test_enum.o: $(TEST_DIR)/test_enum.c
	$(CC) $(CFLAGS) $< -o $@

enum.o: $(SRC_DIR)/enum.c
	$(CC) $(CFLAGS) $< -o $@

munit.o: $(MUNIT_DIR)/munit.c
	$(CC) $(CFLAGS) $< -o $@

test_enum: munit.o enum.o test_enum.o
	$(CC) *.o -o test_enum


# Union
test_unions.o: $(TEST_DIR)/test_unions.c
	$(CC) $(CFLAGS) $< -o $@

unions.o: $(SRC_DIR)/unions.c
	$(CC) $(CFLAGS) $< -o $@

test_union: munit.o unions.o test_unions.o
	$(CC) *.o -o test_union

CLEAR = test_enum test_union

clean:
	rm -f *.o $(CLEAR)

.PHONY: all clean 

