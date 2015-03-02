# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/13 14:40:06 by dsousa            #+#    #+#              #
#    Updated: 2015/03/02 12:17:55 by dsousa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

export	CC		=	gcc

export	INC		=	-I $(PWD)/libft

NAME		=	fractol

CFLAGS	= -Wall -Wextra -Werror

INC			+=	-I includes -I/usr/X11R6/include

INC_DIR		=	includes/

INC_FILES	=	$(NAME).h

INC_SRC			=	$(addprefix $(INC_DIR), $(INC_FILES))

SRC_DIR		=	srcs/

FILES		=	$(NAME).c\
				tools.c\
				julia.c\
				mandelbrot.c\
				key.c\
				burning_ship.c\
				buddhabrot.c\

SRC			=	$(addprefix $(SRC_DIR), $(FILES))

OBJ			=	$(SRC:.c=.o)

LIB			=	-L./ -L/usr/X11/lib -lft -lmlx -lXext -lX11

OBJ_LIB		=	$(libft/SRC_LIB:.c=.o)

HEAD_LIB	=	libft/libft.h

all:			libft.a $(NAME)

libft.a:		libft/$(OBJ_LIB) $(HEAD_LIB)
	@make -C libft

$(NAME):		$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
	@echo ""
	@echo "\033[33m"compilation of $(NAME) : "\033[32m"Success"\033[0m"

$(OBJ):			$(INC_SRC) libft.a

%.o:			%.c $(INC_SRC)
	@echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[31m"Objects of $(NAME) : deleted"\033[0m"

fclean:			clean
	@/bin/rm -f $(NAME)
	@echo "\033[31m"$(NAME) : deleted"\033[0m"
	@make fclean -C libft
re:				fclean all

.PHONY:			all clean fclean re
