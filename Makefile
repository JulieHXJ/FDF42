# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 13:49:27 by junjun            #+#    #+#              #
#    Updated: 2024/12/30 16:21:39 by xhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast -g

RM = rm -f

INCLUDE = -I . -I $(LIBMLX)/include

SRCS = 

SRCOBJ := $(SRCS:%.c=%.o) 

LIBFT = libft/libft.a

LIBMLX = ./MLX42




all: gitclone libmlx libft $(NAME)

gitclone:
    @if [ ! -d "$(LIBMLX)" ]; then \
        echo "Cloning MLX42..."; \
        git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX); \
    fi

libmlx: $(LIBMLX)/build/libmlx42.a

$(LIBMLX)/build/libmlx42.a: $(LIBMLX)
    @cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4



all:	libft $(NAME)

libft: 
	@make -C libft/

$(NAME):	$(SRCOBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDE) $(SRCOBJ) -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "Executable $(NAME) has been created."


%.o:	%.c
	@$(CC) $(CFLAGS) -Imlx $(INCLUDE) -c $< -o $@ 



# %.o: %.c
#     @$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"
# $(NAME): $(OBJS)
#     @$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
#     @echo "Done with $(NAME)"





clean:	
	$(RM) $(SRCOBJ) 
	@make clean -C ./libft
	@rm -rf 
	@echo "Object files have been deleted."

fclean: clean
	$(RM) $(NAME)
	@make fclean -C libft
	@echo "Library has been deleted."

re: fclean all 

.PHONY: all clean fclean re libft