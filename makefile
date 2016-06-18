CC  = gcc
CXX = g++
CFLAGS = -g -O2 -Wall -fPIC -D_GNU_SOURCE -std=c++0x

SRC=.
OBJS = test.o
BIN  = test.run

all: $(BIN)

$(BIN): $(OBJS)
	$(CXX) $(CFLAGS) -o $@ $^ $(INC) $(LIB)

%.o: %.c
	$(CXX) $(CFLAGS) $(INC) $(LIB) -c -o $@ $<

