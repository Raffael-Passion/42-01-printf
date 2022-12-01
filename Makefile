# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhortens <rhortens@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 18:26:28 by rhortens          #+#    #+#              #
#    Updated: 2022/12/01 12:52:54 by rhortens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CFLAGS	=	-Wall -Wextra -Werror

FILES	=	arguments_one.c \
			arguments_two.c \
			ft_printf.c \
			helpers_one.c \
			helpers_two.c \
			ft_putchar_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_strlen.c \

COMP	= cc

PRINTF	= ft_printf.h

LIBFT	= libft.h

OBJS	= $(FILES:.c=.o)

RM		= rm -f

all: $(NAME)

.c.o:
		$(COMP) $(CFLAGS) -c -I $(PRINTF) $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
		ar rcs $(NAME) $(OBJS)
		ranlib $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean
		$(MAKE) all

.PHONY: all clean fclean re bonus