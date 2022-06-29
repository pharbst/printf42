# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 12:18:40 by peter             #+#    #+#              #
#    Updated: 2022/06/23 02:38:03 by pharbst          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CFLAGS	= -Wall -Wextra -Werror -g
CC		= cc

LIBFT	= ./libft
SRCDIR	= ./src
OBJDIR	= ./obj

FILES	=	ft_printf.c\
			ft_print_string.c
			

OBJ		= 	$(addprefix $(OBJDIR)/, $(FILES:.c=.o))

all:		$(NAME)

$(NAME):	$(OBJ)
	make -C $(LIBFT)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c ./ft_printf.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:	
	@rm -rf $(OBJ)
	rm -rf $(OBJDIR)
	make clean -C $(LIBFT)

fclean:
	@rm -rf $(OBJ)
	rm -rf $(OBJDIR)
	rm -f $(NAME)
	make fclean -C $(LIBFT)

cleanall:	clean
	make clean -C $(LIBFT)

fcleanall:	fclean
	make fclean -C $(LIBFT)
	clear

re:			fclean all

reall:		fcleanall all

.PHONY: 	clean fclean cleanall fcleanall reall all re