# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 12:18:40 by peter             #+#    #+#              #
#    Updated: 2022/07/01 03:20:25 by pharbst          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CFLAGS	= -Wall -Wextra -Werror -g
CC		= cc

LIBFT	= ./libft
SRCDIR	= ./src
OBJDIR	= ./obj

FILES	=	ft_printf.c\
			ft_printf_helper.c
			

OBJ		= 	$(addprefix $(OBJDIR)/, $(FILES:.c=.o))

all:		$(NAME)

$(NAME):	$(OBJ)
	@echo make ft_printf
	@make -C $(LIBFT)
	@cp libft/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJ)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c ./ft_printf.h
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@echo make clean ft_printf
	@rm -rf $(OBJ)
	rm -rf $(OBJDIR)
	@make clean -C$(LIBFT)

fclean:
	@echo make fclean ft_printf
	@rm -rf $(OBJ)
	rm -rf $(OBJDIR)
	rm -f $(NAME)
	rm -f a.out
	@make fclean -C $(LIBFT)

re:			fclean all

.PHONY: 	clean fclean all re