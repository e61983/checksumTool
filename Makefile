TARGET = checksum
CC ?= gcc
CFLAGS = -Wall -std=c11 -O3

$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) $< -o $@.out

.PHONY: clean
clean:
	rm -rf *.out *.o



