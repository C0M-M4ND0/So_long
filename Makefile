# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oabdelha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 12:17:54 by oabdelha          #+#    #+#              #
#    Updated: 2022/04/15 16:11:05 by oabdelha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CM = cc

FLAG_MLX = -lmlx -framework OpenGL -framework AppKit 

FLAG = -Wall -Wextra -Werror

SRC = check_map.c so_long.c so_long_utils_2.c so_long_utils.c ft_split.c put_images.c move_player.c search.c ft_itoa.c enmy.c

CNVRT = $(SRC:.c=.o)

INCLUDE = so_long.h

all: $(NAME)

$(NAME): $(CNVRT) $(INCLUDE)
	@cc $(FLAG) $(SRC) $(FLAG_MLX) -o so_long

%.o : %.c $(INCLUDE)
	@$(CM) $(FLAG) -o $@  -c $< 

clean:
	@rm -rf $(CNVRT)

fclean: clean
	@rm -rf $(NAME) so_long

re: fclean all
