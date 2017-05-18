.PHONY:clean all
CC=g++
CPPFLAGS=-Wall -g
BIN=chatsrv chatcli
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

