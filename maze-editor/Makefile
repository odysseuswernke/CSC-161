CC := clang
CFLAGS := -g -Wall

all: maze

clean:
	rm -rf maze maze.dSYM

maze: maze.c
	$(CC) $(CFLAGS) -o maze maze.c -lncurses

.PHONY: all clean
