CC := clang
CFLAGS := -Wall

all: game

clean:
	rm -f game

game: game.c
	$(CC) $(CFLAGS) -o game game.c

.PHONY: all clean
