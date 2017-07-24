# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpierce <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/25 10:27:14 by bpierce           #+#    #+#              #
#    Updated: 2017/07/24 14:46:01 by bpierce          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = ft_printf \
		manage_printlst \
		manage_percentid set_percentid set_helper \
		manage_datafmt \
		pf_character pf_string pf_signedint pf_unsignedint pf_percent \
		pf_widechar pf_widestr\
		libft_memfuncs libft_strfuncs1 libft_strfuncs2 libft_strfuncs3 \
		libft_strfuncs4 libft_strfuncs5 libft_wcharfuncs1 libft_wcharfuncs2

C_LOC = src/
C_NAM = $(addsuffix .c, $(FILES))
C_SRC = $(addprefix $(C_LOC), $(C_NAM))

O_LOC = obj/
O_NAM = $(addsuffix .o, $(FILES))
O_SRC = $(addprefix $(O_LOC), $(O_NAM))

H_LOCS = -I inc

C_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(O_SRC)
	@echo Compiling $@ library...
	@ar rcs $@ $^
	@echo
	@echo --------xxXXXXXXXXxx--------
	@echo -----xXX------------XXx-----
	@echo ---xXX--- COMPLETE ---XXx---
	@echo ---xXX---- YIPPEE ----XXx---
	@echo -----xXX------------XXx-----
	@echo --------XXxxxxxxxxXX--------
	@echo

$(O_LOC)%.o: $(C_LOC)%.c
	@echo Re-compiling $< file...
	@gcc $(C_FLAGS) $(H_LOCS) -o $@ -c $<

test: $(NAME)
	@gcc $(C_FLAGS) $(H_LOCS) $(NAME) main_for_testing.c
	@./a.out

clean:
	@echo Cleaning .o files ...
	@/bin/rm -rf $(O_SRC)
	@echo ... Successfully removed .o files

fclean: clean
	@echo Cleaning $(NAME) ...
	@/bin/rm -f $(NAME)
	@echo ...Successfully removed $(NAME)

re: fclean all

.PHONY: all test clean fclean re
