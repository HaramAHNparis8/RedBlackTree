CC = gcc


CFLAGS = -Wall -Wextra -std=c11 -fsanitize=address -g


TARGET = ArbreRougeEtNoir


SRC = main.c util.c arbre.c


OBJ = $(SRC:.c=.o)


all: $(TARGET)


$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ) $(TARGET)
