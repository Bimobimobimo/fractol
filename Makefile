# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 12:56:38 by lcollong          #+#    #+#              #
#    Updated: 2024/12/16 15:15:16 by lcollong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ~ Variables ~

NAME = fractol
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
SRCS = fractol.c \
		creation.c \
		render.c \
		events.c \
		utils.c
OBJS = $(SRCS:%.c=%.o)
LIBFT = libft
MLX = minilibx-linux
MLX_LIB = $(MLX)/libmlx.a
LIBFT_LIB = $(LIBFT)/libft.a

# ~ Regles ~

all : $(NAME)

$(MLX_LIB) :
	@echo "\nBuffering MiniLibX...\n"
	make -C $(MLX)

$(LIBFT_LIB) :
	@echo "\nBuffering Libft...\n"
	make -C $(LIBFT)

$(NAME) : $(OBJS) $(MLX_LIB) $(LIBFT_LIB)
	$(CC) $(OBJS) -L$(MLX) -lmlx -L$(LIBFT) -lft -lX11 -lXext -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I$(MLX) -I$(LIBFT) -c $< -o $@

clean :
	rm -f $(OBJS)
	make -C $(MLX) clean
	make -C $(LIBFT) clean

fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re : fclean all

.PHONY : all clean fclean re
