# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 06:26:56 by zouddach          #+#    #+#              #
#    Updated: 2024/03/17 01:44:06 by zouddach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS= -Werror -Wall -Wextra
NAME=push_swap
FILES=push_swap.c utils_1.c utils2.c
SRC_DIR=SRC/
HEADER=$(SRC_DIR)push_swap.h
SRC=$(addprefix $(SRC_DIR), $(FILES))
OBJ_DIR=OBJ/
OBJ=$(addprefix $(OBJ_DIR), $(FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re