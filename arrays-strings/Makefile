CC := clang
CFLAGS := -Wall -Werror

all: max-min reverse1 reverse2

clean:
	rm -f max-min reverse1 reverse2

max-min: max-min.c
	$(CC) $(CFLAGS) -o max-min max-min.c

reverse1: reverse1.c
	$(CC) $(CFLAGS) -o reverse1 reverse1.c

reverse2: reverse2.c
	$(CC) $(CFLAGS) -o reverse2 reverse2.c

face: face.c
	$(CC) $(CFLAGS) -o face face.c

.PHONY: all clean
