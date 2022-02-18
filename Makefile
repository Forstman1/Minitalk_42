

CC	= gcc
flags = -Wall -Werror -Wextra
NAME = libminitalk.a
C = client
S = server

.PHONY: $(NAME) all re clean fclean bonus

all : $(NAME)

$(NAME) : server.c client.c
	@make -C Printf/
	@make -C libft/
	@$(CC) $(flags) server.c libft/libft.a Printf/libftprintf.a  -o server
	@$(CC) $(flags) client.c libft/libft.a Printf/libftprintf.a -o client
	@echo "good to go"

clean : 
	@rm -f libft/*.o Printf/*.o

fclean : clean
	@rm -f libft/*.a Printf/*.a $(S) $(C)

re : fclean all

bonus : re

execute_server : 
	@./server
	@echo "executing server"
