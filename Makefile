NAME=serverclient.a

CC=gcc
CFLAGS=-g -Wall -Wextra -Werror
printf= ft_printf/libftprintf.a

CLIENT = client
SERVER = server

$(NAME): $(SERVER) $(CLIENT)

$(SERVER):
	make -C ./ft_printf
	$(CC) $(CFLAGS) server.c $(printf) -o server

$(CLIENT):
	$(CC) $(CFLAGS) client.c $(printf) -o client

all: $(SERVER) $(CLIENT)

clean:
	make fclean -C ./ft_printf
	rm -rf server client

fclean: clean

re: fclean all

.PHONY: all clean fclean re