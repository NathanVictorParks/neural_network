# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall -std=c++11

# the build target executable:
TARGET = network
CLASS1 = node
CLASS2 = layer
TEST = main

all: $(TARGET)

$(TARGET): $(CLASS1).o $(CLASS2).o $(TEST).o
	$(CC) $(CFLAGS) -o $(TARGET) $(CLASS1).o $(CLASS2).o $(TEST).o

$(CLASS1).o: $(CLASS1).cc $(CLASS1).h
	$(CC) $(CFLAGS) -c $(CLASS1).cc

$(CLASS2).o: $(CLASS2).cc $(CLASS2).h
	$(CC) $(CFLAGS) -c $(CLASS2).cc

$(TEST).o: $(TEST).cc $(CLASS1).h $(CLASS2).h
	$(CC) $(CFLAGS) -c $(TEST).cc

clean:
	$(RM) -f $(TARGET) $(CLASS1).o $(CLASS2).o $(TEST).o
