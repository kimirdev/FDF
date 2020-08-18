# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/09 18:41:18 by gyellowj          #+#    #+#              #
#    Updated: 2020/02/09 18:41:28 by gyellowj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_DIR = ./src/
LIB_DIR = ./libft/
MINI_DIR = ./minilibx_macos/
OBJ_DIR = ./obj/
SRC_INC_DIR = ./includes/
LIB_INC_DIR = ./libft/

CFLGS = -Wall -Werror -Wextra
CFLGS_DBG = -g -fsanitize=address
LFLGS = -L$(LIB_DIR) -L$(MINI_DIR) -lft -lm -lmlx
CC = gcc

LIBFT = $(LIB_DIR)/libft.a
MINI = $(MINI_DIR)/libmlx.a

SRC_FILES = get_next_line.c \
			projections.c \
			read_map.c \
			x_rotate.c \
			y_rotate.c \
			z_rotate.c \
			deal_key.c \
			valid.c \
			main.c \
			dop.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

INCL = -I$(SRC_INC_DIR) -I$(LIB_INC_DIR) -I$(MINI_DIR)

.PHONY: all clean fclean re

all: $(NAME)

-include: $(DEPS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLGS) -c -o $@ $< $(INCL)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIB_DIR)

$(MINI):
	@$(MAKE) -C $(MINI_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MINI)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCL) $(LFLGS) -framework OpenGL -framework AppKit

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIB_DIR) clean
	@$(MAKE) -C $(MINI_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIB_DIR) fclean
	@$(MAKE) -C $(MINI_DIR) clean

re: fclean all
