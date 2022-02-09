

CC	= gcc
Flags = -Wall -Werror -Wextra
NAME = server


all: $(NAME)

$(NAME) : server.c client.c
	@$(CC) server.c libft.a -o server
	@$(CC) client.c libft.a -o client
	@echo "good to go"


execute_server : $(NAME) 
	./server
	@echo "executing server"
