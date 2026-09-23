CC     = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

TARGETS = task1 task2

all: $(TARGETS)

task1: task1.c
	$(CC) $(CFLAGS) -o task1 task1.c

task2: task2.c
	$(CC) $(CFLAGS) -o task2 task2.c

clean:
	rm -f $(TARGETS)

.PHONY: all clean