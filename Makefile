TARGET=main

# all .cpp files in this directory are my sources
SOURCES=$(wildcard *.cpp)

OBJS=$(SOURCES:.cpp=.o)

INC_DIR=../include
CC=g++
CFLAGS= -c -pedantic -Wall -Wconversion -ansi -g -I$(INC_DIR)

LDLIBS = -lgtest -lgtest_main -pthread

CXXFLAGS=$(CFLAGS)
LDFLAGS=-g

.PHONY: clean run gdb

$(TARGET): $(OBJS)

include .depends

.depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > .depends

clean:
	rm -f $(OBJS) $(TARGET) .depends

run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET)