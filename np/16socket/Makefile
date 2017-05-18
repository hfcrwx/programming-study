.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN=srv cli
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
cli:cli.o sysutil.o
	$(CC) $(CFLAGS) $^ -o $@
clean:
	rm -f *.o $(BIN)

