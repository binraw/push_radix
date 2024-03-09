NAME = push_swap
PRINTFNAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
PRINTFDIR = ./printf
LIBFTDIR = ./printf/libft
DIR_OBJ = .object/
RM = rm -Rf
SRCS = lst_create.c main.c swap_command.c lst_utils.c threenum.c fivenum.c finder.c big_lst_algo.c check.c count_rotate.c rotation.c check_error.c rotation_utils.c transfer_utils.c big_utils.c
FT_PRINTF = ./printf/libftprintf.a


OBJS = $(patsubst %.c, ${DIR_OBJ}%.o, ${SRCS})

all: ft_printf $(NAME)

ft_printf: ${FT_PRINTF_DIR}
	${MAKE} -C ./printf all


${DIR_OBJ}%.o: %.c push_swap.h Makefile
	mkdir -p $(shell dirname $@)
	$(CC) ${CFLAGS} -c $< -o $@


$(NAME): $(OBJS) $(FT_PRINTF)
	$(CC) $(OBJS) $(FT_PRINTF) -o $(NAME)

clean:
	${RM} ${DIR_OBJ}
	${MAKE} -C ./printf clean

fclean: clean
	${RM} ${NAME}
	${MAKE} -C ./printf fclean



re: fclean all

.PHONY: all clean fclean re

