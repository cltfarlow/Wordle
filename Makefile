CC = gcc
CFLAGS = -Wall -ansi -g

TARGET = Wordle

SRC = menu.c play.c check_letter.c CheckWord.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)