# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 12:18:40 by peter             #+#    #+#              #
#    Updated: 2022/05/24 17:25:23 by pharbst          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CFLAGS	= -Wall -Wextra -Werror
CC		= gcc

LIBFT	= ./libft/
SRCDIR	= ./src/
OBJDIR	= ./obj/

FILES	=	ft_printf.c\
			

OBJ		= 	$(addprefix $(OBJDIR)/, $(FILES:.c=.o))

all:		$(NAME)

$(NAME):	$(OBJ)
	@make -C $(LIBFT)
	@cp libft/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJ)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c ./ft_printf.h
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:	
	rm -rf $(OBJ)
	rm -rf $(OBJDIR)

fclean:		clean
	@rm -f $(NAME)

cleanall:	clean
	@make clean -C $(LIBFT)

fcleanall:	fclean
	@make fclean -C $(LIBFT)
	@clear

re:			fclean all

reall:		fcleanall all

.PHONY: 	clean fclean cleanall fcleanall reall all re