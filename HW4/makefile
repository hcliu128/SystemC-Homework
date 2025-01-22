CC = g++
CFLAGS = -O1 -Wall
HDR = Node.h List.h
SRC = main.cpp
OBJ = main.o
TARGET = list

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.cpp $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
