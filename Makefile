NAME=downtime

CC=gcc
CFLAGS=-Wall -Wextra -Werror

SRC= main.c utils.c
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

install: all
	mkdir -p ${HOME}/.local/bin
	mv ./downtime ${HOME}/.local/bin
