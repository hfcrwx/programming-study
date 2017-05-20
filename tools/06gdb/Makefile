.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN=simple reverse bugging
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
main:main.o search.o
	$(CC) $^ -o $@
clean:
	rm -f *.o $(BIN)
