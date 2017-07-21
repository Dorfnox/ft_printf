# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpierce <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/25 10:27:14 by bpierce           #+#    #+#              #
#    Updated: 2017/07/21 11:11:56 by bpierce          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = ft_printf \
		manage_printlst \
		manage_percentid set_percentid set_helper \
		manage_datafmt \
		pf_character pf_string pf_signedint pf_unsignedint \
		libft_memfuncs libft_strfuncs1 libft_strfuncs2 libft_strfuncs3 \
		libft_strfuncs4

C_LOC = src/
C_NAM = $(addsuffix .c, $(FILES))
C_SRC = $(addprefix $(C_LOC), $(C_NAM))

O_LOC = obj/
O_NAM = $(addsuffix .o, $(FILES))
O_SRC = $(addprefix $(O_LOC), $(O_NAM))

H_LOCS = -I inc

C_FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(O_SRC)
	@ar rcs $@ $^

$(O_LOC)%.o: $(C_LOC)%.c
	@gcc $(C_FLAGS) $(H_LOCS) -o $@ -c $<

clean:
	@/bin/rm -rf $(O_SRC)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
