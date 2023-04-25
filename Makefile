NAME = libftprintf.a

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

SRCS = ft_printf.c ft_printf_2.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

%.o:%.c
	$(CC) $(FLAGS) -o $@ -c $< -I $(LIBFT_PATH)

$(NAME) : $(OBJS)
	cp $(LIBFT) $(NAME)
	ar -rc $(NAME) $(OBJS)

clean:
	make clean -C $(LIBFT_PATH)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
