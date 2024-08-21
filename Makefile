SRC=src
INC=inc

CC=gcc

SOURCES=\
    $(SRC)/main.c

NAME=default

all:
	$(CC) $(SOURCES) -o $(NAME).elf
