CC = gcc
CFLAGS = -Wall -Wextra
TARGET = fifo
SRC = fifo.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) *.o

.PHONY: all clean
