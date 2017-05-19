CXX       = g++
BIN       = test2
OBJS      = test2.o
CXXFLAGS  = -Wall -g
.PHONY: all clean print
all:print $(BIN)
print:
	@echo "----- make all in $(PWD) -----"
$(BIN):$(OBJS)
	$(CXX) $(OBJS) -o $@
.o:%.cpp
	$(CXX) -c $<
clean:
	@echo "----- make clean in $(PWD) -----"
	rm -f $(BIN) $(OBJS)
