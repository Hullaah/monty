CC = gcc
CFLAGS = -Wall -Werror -g -Wextra -pedantic -std=gnu11
PROG = monty
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c monty.h
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f $(OBJS) $(PROG)

.PHONY:
	all clean

