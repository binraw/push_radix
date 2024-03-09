
NAME = libftprintf.a
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra 
LIBFTDIR = ./libft

SRCS =  ft_printf.c \
                ft_printf_hexa.c \
                ft_printf_num.c \
                ft_printf_str.c \
				ft_printf_char.c \
				ft_printf_putmem.c 

OBJS = ft_printf.o \
                ft_printf_hexa.o \
                ft_printf_num.o \
                ft_printf_str.o \
				ft_printf_char.o \
				ft_printf_putmem.o

LIB = ft_printf.h

all: makelibft $(NAME)


$(NAME): $(OBJS) 
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c $(LIB)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

makelibft:
	@make -C $(LIBFTDIR)

clean:
	@rm -f $(OBJS)
	@cd $(LIBFTDIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean



re: fclean all 

.PHONY:                         all bonus clean fclean re 

