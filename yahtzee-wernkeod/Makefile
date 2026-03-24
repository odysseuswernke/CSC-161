CC := clang
CFLAGS := -g -Wall -Werror

all: yahtzee

clean:
	rm -rf yahtzee yahtzee.dSYM

yahtzee: yahtzee.c
	$(CC) $(CFLAGS) -o yahtzee yahtzee.c

.PHONY: all clean
