# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhortens <rhortens@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 18:26:28 by rhortens          #+#    #+#              #
#    Updated: 2023/02/08 21:00:43 by rhortens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CFLAGS	=	-Wall -Wextra -Werror

FILES	=	arguments_one.c \
			arguments_two.c \
			ft_printf.c \
			printf_helpers.c \
			printf_utils.c \

COMP	= cc

PRINTF	= ft_printf.h

OBJS	= $(FILES:.c=.o)

RM		= rm -f

GREEN	= \033[0;32m
WHITE	= \033[0m

all: $(NAME)

.c.o:
		$(COMP) $(CFLAGS) -c -I $(PRINTF) $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
		ar rcs $(NAME) $(OBJS)
		ranlib $(NAME)
		@echo "$(GREEN)printf compiled!$(WHITE)"

clean:
		$(RM) $(OBJS)
		@echo "$(GREEN)printf objective files cleaned!$(WHITE)"

fclean: clean
		$(RM) $(NAME)
		@echo "$(GREEN)printf executable files cleaned!$(WHITE)"

re: fclean
		$(MAKE) all
		@echo "$(GREEN)cleaned and rebuilt everything for printf!$(WHITE)"

.PHONY: all clean fclean re bonus