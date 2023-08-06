NAME = libftprintf.a

FILES = ft_printf.c ft_printf_helpers.c

OBJS = $(FILES:.c=.o)
# BONUS_OBJS = $(BONUS_FILES:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar rus $(NAME) $(OBJS)

# bonus: $(OBJS) $(BONUS_OBJS)
# 	ar rus $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
