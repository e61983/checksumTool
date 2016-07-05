TARGET = checksum
CC ?= gcc.exe
CFLAGS = -Wall -std=c11 -O3

$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) $< -o $@.exe

.PHONY: clean
clean:
	rm -rf *.exe *.o



