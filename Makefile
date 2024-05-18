# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 18:22:40 by ksainte           #+#    #+#              #
#    Updated: 2024/05/18 16:49:56 by ksainte          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS_1 = src/push_swap/main.c
SRCS_2 = src/push_swap/calculate_b.c \
         src/push_swap/calculate_cost.c \
         src/push_swap/utils.c \
		 src/push_swap/utils_2.c \
         src/push_swap/commands_a.c \
		 src/push_swap/commands_b.c \
		 src/push_swap/commands_a_b.c \
		 src/push_swap/help_calculate_b.c \
		 src/push_swap/help_free.c \
		 src/push_swap/help_move_till_3_bis.c \
		 src/push_swap/help_move_till_3.c \
		 src/push_swap/help_process.c \
		 src/push_swap/sort.c \

LIBFT_PATH = Libft
LIBFT_ARCHIVE = $(LIBFT_PATH)/libft.a
EXEC_NAME = push_swap


all: $(EXEC_NAME)

$(EXEC_NAME): $(SRCS_1) $(SRCS_2) $(LIBFT_ARCHIVE)
	$(CC) $(CFLAGS) -o $@ $(SRCS_1) $(SRCS_2) -L$(LIBFT_PATH) -lft

$(LIBFT_ARCHIVE):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(EXEC_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
