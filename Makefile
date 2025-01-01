# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junjun <junjun@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 13:49:27 by junjun            #+#    #+#              #
#    Updated: 2025/01/01 21:39:21 by junjun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast -g

RM = rm -f

HEADERS = -I. -I $(MLX_DIR)/include -I $(LIBFT_DIR)

SRCS_DIR = ./src

SRCS = $(SRCS_DIR)/

SRCOBJ := $(SRCS:%.c=%.o) 

MLX_DIR		:= ./lib/MLX42

MLX		:= $(MLX_DIR)/build/libmlx42.a

LIBFT_DIR	:= ./lib/libft

LIBFT 	:= $(LIBFT_DIR)/libft.a

LIBS = $(LIBFT) $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm


all: gitclone libmlx libft $(NAME)

gitclone:
    @if [ ! -d "$(LIBMLX)" ]; then \
        echo "Cloning MLX42..."; \
        git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX); \
    fi

libmlx: $(LIBMLX)/build/libmlx42.a

$(LIBMLX)/build/libmlx42.a: $(LIBMLX)
    @cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft: 
	@make -C libft/

$(NAME):	$(SRCOBJ) 
	$(CC) $(CFLAGS) $(LIBS) $(HEADERS) $(SRCOBJ) -o $(NAME)
	@echo "Executable $(NAME) has been created."

%.o: %.c
    @$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

clean:	
	$(RM) $(SRCOBJ) 
	@make clean -C ./libft
	@echo "Object files have been deleted."

fclean: clean
	$(RM) $(NAME)
	@make fclean -C libft
	@echo "Library has been deleted."

re: fclean all 

.PHONY: all clean fclean re libft libmlx gitclone