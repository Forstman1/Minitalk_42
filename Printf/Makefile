

CFILES  = ft_printf.c ft_printf_utils1.c ft_printf_utils2.c ft_printf_bonus.c ft_printf_mandatory.c

OFILES	= $(CFILES:.c=.o)


CC	= gcc
NAME = libftprintf.a
W	= -Wall -Wextra -Werror
INT	= ft_printf.h

all : $(NAME)

$(NAME) : $(OFILES) $(INT)
	@ar -r $(NAME) $(OFILES)
	@echo "libftprintf.a been created"

%.o:%.c
	@$(CC) $(W) -o $@ -c $<

bonus : all

clean:
	@rm -f $(OFILES)

fclean:	clean
	@rm -f  $(NAME) 


re : fclean all


.PHONY: re fclean clean