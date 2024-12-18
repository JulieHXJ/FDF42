# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junjun <junjun@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 13:49:27 by junjun            #+#    #+#              #
#    Updated: 2024/12/17 17:01:33 by junjun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf

LIBFT = libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

INCLUDE = -I.

SRCS = 

SRCOBJ := $(SRCS:%.c=%.o) 


.PHONY: all clean fclean re libft

all:	libft $(NAME)

libft: 
	@make -C libft/

$(NAME):	$(SRCOBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDE) $(SRCOBJ) -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "Executable $(NAME) has been created."


%.o:	%.c
	@$(CC) $(CFLAGS) -Imlx $(INCLUDE) -c $< -o $@ 

clean:	
	$(RM) $(SRCOBJ) 
	@make clean -C libft
	@echo "Object files have been deleted."

fclean: clean
	$(RM) $(NAME)
	@make fclean -C libft
	@echo "Library has been deleted."

re: fclean all 