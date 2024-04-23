CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=gnu99

SRC = main.c function_A.c function_B.c
OBJ = $(SRC:.c=.o)

all: lab1

lab1: $(OBJ)
	$(CC) $(CFLAGS) -o lab1 $(OBJ) -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
