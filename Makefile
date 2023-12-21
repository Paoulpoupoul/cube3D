# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 14:48:58 by lkoletzk          #+#    #+#              #
#    Updated: 2023/12/21 15:55:04 by lkoletzk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = $(addprefix src/, parsing.c parsing_2.c parsing_map.c parsing_map_2.c err_msg.c)\
	src/main.c \
	src/start.c \
	src/init_struc.c \
	src/init.c \
	src/textures.c \
	src/colors.c \
	src/hooks.c \
	src/draw.c \
	src/draw_utils.c \
	src/event.c \
	src/exit.c \
	src/keys.c \
	src/raycasting.c \
	src/ray_init.c \
	src/ray_update.c \
	src/ray_utils.c

OBJ			= $(SRC:.c=.o)

LFT_PATH	= ./libft/
LIBFT		= libft.a

MLX_PATH	= ./mlx/
MLX			= libmlx.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address
LIBFT_CF 	= -L$(LFT_PATH)
MLX_CF 		= -L$(MLX_PATH)
CLIB_CF		= -lft -lm -lbsd -lmlx -lXext -lX11

all : $(NAME)

$(NAME): $(OBJ) $(LFT_PATH)$(LIBFT) $(MLX_PATH)$(MLX)
	@ echo "\033[97;0m🚧 cub3D in progress 🚧\033[0m\n"
	@ $(CC) $(CFLAGS) $(OBJ) $(LIBFT_CF) $(MLX_CF) $(CLIB_CF) -o $(NAME)
	@ echo "\033[32;1mCUB3D READY ✅\033[0m\n"

$(LFT_PATH)$(LIBFT):
	@ echo "\n\033[97;0m🚧 creating libft 🚧\033[0m\n"
	@ make --no-print-directory -C $(LFT_PATH)
	@ echo "\033[32;1mLIBFT READY ✅\033[0m\n"

$(MLX_PATH)$(MLX):
	@ echo "\n\033[97;0m🚧 creating MLX 🚧\033[0m\n"
	@ make --no-print-directory -C $(MLX_PATH)
	@ echo "\033[32;1mMLX READY ✅\033[0m\n"

%.o: %.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LFT_PATH)
	rm -f $(OBJ)
	@ echo "\033[32;1m★ objects cleaned ★\033[0m\n"

fclean: clean
	$(MAKE) fclean -C $(LFT_PATH)
	rm -f $(NAME) $(MINILIBX)

re: fclean all

norm :
	@echo -e '		$(Purple)Norminette cub3D$(Color_Off)\n'
	@norminette $(SRC) include
	@echo -en '\n'

.PHONY: all clean fclean re orm
