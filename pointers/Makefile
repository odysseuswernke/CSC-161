CC := clang
CFLAGS := -Wall

all: divide exchange max time

clean:
	rm -f divide exchange max time

divide: divide.c
	$(CC) $(CFLAGS) -o divide divide.c

exchange: exchange.c
	$(CC) $(CFLAGS) -o exchange exchange.c

max: max.c
	$(CC) $(CFLAGS) -o max max.c

time: time.c
	$(CC) $(CFLAGS) -o time time.c

.PHONY: all clean
