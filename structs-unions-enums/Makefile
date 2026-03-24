CC := clang
CFLAGS := -g -Wall

all: connect-four-stats unions racket_values

clean:
	rm -rf connect-four-stats connect-four-stats.dSYM unions unions.dSYM racket_values racket_values.dSYM

connect-four-stats: connect-four-stats.c
	$(CC) $(CFLAGS) -o connect-four-stats connect-four-stats.c

unions: unions.c
	$(CC) $(CFLAGS) -o unions unions.c

racket_values: racket_values.c
	$(CC) $(CFLAGS) -o racket_values racket_values.c

.PHONY: all clean
