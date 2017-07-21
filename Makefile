# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpierce <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/25 10:27:14 by bpierce           #+#    #+#              #
#    Updated: 2017/07/20 16:42:36 by bpierce          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test.out

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

LIB_LOC = libft/
LIB_NAM = libft.a
LIB_SRC = $(addprefix $(LIB_LOC), $(LIB_NAM))

H_LOCS = -I inc -I libft/inc

C_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(O_SRC) $(LIB_SRC)
	@echo Compiling executable... $@
	@gcc $(C_FLAGS) $^ -o $@
	@echo
	@echo --------xxXXXXXXXXxx--------
	@echo -----xXX------------XXx-----
	@echo ---xXX--- COMPLETE ---XXx---
	@echo ---xXX---- YIPPEE ----XXx---
	@echo -----xXX------------XXx-----
	@echo --------XXxxxxxxxxXX--------
	@echo

$(O_LOC)%.o: $(C_LOC)%.c
	@echo Re-compiling src file... $<
	@gcc $(C_FLAGS) $(H_LOCS) -o $@ -c $<

$(LIB_SRC): force
	@echo ----------- Checking Libft Library -----------
	@make -C $(LIB_LOC)
	@echo ----------- Library Check Complete -----------

force:
	@true

clean:
	@/bin/rm -rf $(O_SRC)
	@make clean -C $(LIB_LOC)

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIB_LOC)

re: fclean all

.PHONY: all force clean fclean re
