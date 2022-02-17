

CC	= gcc
flags = -Wall -Werror -Wextra
NAME = libminitalk.a

.PHONY: $(NAME) all re clean fclean bonus

all : $(NAME)

$(NAME) : server.c client.c
	make -C Printf/
	make -C libft/
	@$(CC) $(flags) server.c libft/libft.a Printf/libftprintf.a  -o server
	@$(CC) $(flags) client.c libft/libft.a Printf/libftprintf.a -o client
	@echo "good to go"

clean :
	@rm -r $(NAME)

fclean : clean
	@rm -r client server

re : fclean all

# execute_server : 
# 	./server
# 	@echo "executing server"
