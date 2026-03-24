all: farm

farm: farm.c cow.c cow.h chicken.c chicken.h sheep.c sheep.h util.c util.h
	clang -o farm farm.c chicken.c cow.c sheep.c util.c

clean:
	rm -f farm

.PHONY: all clean