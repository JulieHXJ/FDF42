# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 13:49:27 by junjun            #+#    #+#              #
#    Updated: 2025/01/10 19:15:16 by xhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# vpath %.c src
# vpath %.c lib


NAME = fdf

CC = gcc

# CFLAGS = -Wall -Wextra -Werror -Imlx -g libmlx42.a -Iinclude -lglfw
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast -g


HEADERS = -I. -I $(LIBMLX)/include

SRCS = src/read_map.c src/color.c src/adj_value.c src/iso_convert.c src/draw.c src/hook.c src/error.c src/main.c

SRCOBJ = $(SRCS:%.c=%.o) 
# SRCOBJ = $(addprefix /$())

LIBMLX = ./lib/MLX42

LIBFT = ./lib/libft

LIB = $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

RM = rm -f

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
	@make -C $(LIBFT)

$(NAME):	$(SRCOBJ) 
	$(CC) $(CFLAGS) $(SRCOBJ) $(LIB) $(HEADERS) -o $(NAME)
	@echo "Executable $(NAME) has been created."

%.o:	%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) 

clean:	
	$(RM) $(SRCOBJ) 
	make clean -C $(LIBFT)
	@echo "Object files have been deleted."

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)
	@echo "Library has been deleted."

re: fclean all 

.PHONY: all clean fclean re libft libmlx gitclone