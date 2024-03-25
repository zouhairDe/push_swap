# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 06:26:56 by zouddach          #+#    #+#              #
#    Updated: 2024/03/25 01:47:57 by zouddach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Werror -Wall -Wextra
NAME=push_swap
BONUS_NAME=checker
FILES=push_swap.c utils_1.c utils2.c checks.c functions.c mini_algo.c push_functions.c quicksort.c ft_split.c error_manager.c
BONUS_FILES=push_swap_bonus.c utils_1_bonus.c utils2_bonus.c checks_bonus.c functions_bonus.c mini_algo_bonus.c push_functions_bonus.c ft_split_bonus.c error_manager_bonus.c
GNL_FILES=BONUS/GNL/get_next_line_bonus.c BONUS/GNL/get_next_line_utils_bonus.c
GNL_HEADER=BONUS/GNL/get_next_line_bonus.h
SRC_DIR=SRC/
HEADER=$(SRC_DIR)push_swap.h
HEADER=$(BONUS_DIR)push_swap_bonus.h
SRC=$(addprefix $(SRC_DIR), $(FILES))
OBJ_DIR=OBJ/
OBJ=$(addprefix $(OBJ_DIR), $(FILES:.c=.o))
BONUS_OBJ_DIR=BONUS_OBJ/
BONUS_DIR=BONUS/
BONUS=$(addprefix $(BONUS_DIR), $(BONUS_FILES))
BONUS_OBJ=$(addprefix $(BONUS_OBJ_DIR), $(BONUS_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)%.o: $(BONUS_DIR)%.c $(BONUS_HEADER)
	@mkdir -p $(BONUS_OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus:	$(BONUS_OBJ) $(GNL_HEADER)
	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(GNL_FILES) -o $(BONUS_NAME)

clean:
	@rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re