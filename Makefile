# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thgiraud <thgiraud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 18:00:18 by thgiraud          #+#    #+#              #
#    Updated: 2016/11/24 18:27:51 by thgiraud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror

PATH_SRC = ./srcs/
PATH_INC = ./includes/
PATH_OBJ = ./obj/
PATH_LIB = ./libft/

SRC = $(addprefix $(PATH_SRC),$(NAME_SRC))
OBJ = $(addprefix $(PATH_OBJ),$(NAME_OBJ))
INC = $(addprefix -I,$(PATH_INC))

NAME_OBJ = $(SRC_NAME:.c=.o)
NAME_INC = fillit.h
NAME_SRC = //ADD SRCS

.PHONY: all, $(NAME), clean, fclean, re

all: $(NAME)

$(NAME):	$(OBJ)
			echo
			make -C $(PATH_LIB)
			$(CC) -o $(NAME) $(OBJ) -lm -L $(PATH_LIB) -lft
			echo "FILLIT:\t\tFillit ready"

$(PATH_OBJ)%.o: $(PATH_SRC)%.c
			mkdir -p $(PATH_OBJ)
			$(CC) $(CFLAGS) $(INC) -o -c <
			echo -n =

clean:
			make -C $(PATH_LIB) clean
			rm -rf $(PATH_OBJ)
			echo "FILLIT:\t\tRemoving OBJ path: ./obj/"

fclean: 	clean
			make -C $(PATH_LIB) fclean
			rm -f $(NAME)
			echo "FILLIT:\t\tRemoving fillit executable"

re:			fclean all
