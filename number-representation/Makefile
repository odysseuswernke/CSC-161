CC := clang
CFLAGS := -Wall

all: integer bitwise float

clean:
	rm -f integer bitwise float

integer: integer.c
	$(CC) $(CFLAGS) -o integer integer.c

bitwise: bitwise.c
	$(CC) $(CFLAGS) -o bitwise bitwise.c

float: float.c
	$(CC) $(CFLAGS) -o float float.c

.PHONY: all clean
