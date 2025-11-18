CC = gcc
CFLAGS = -Wall -ansi -g

TARGET = Wordle

SRC = menu.c play.c Input.c CheckWord.c Output.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)