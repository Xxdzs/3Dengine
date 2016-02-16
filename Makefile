#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/16 12:17:30 by angagnie          #+#    #+#              #
#    Updated: 2016/02/16 15:06:50 by angagnie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# === Editable ===
NAME:=fdf
FILES:=main
# ================

# ==== Standard ====
CC:=clang
CCHPATH:=cache/
SRCPATH:=src/
HDRPATH:=include/
LFLAGS:=-I $(HDRPATH)
LIBFLAGS:=-lmlx -framework OpenGL -framework AppKit
CFLAGS:=-Wall -Wextra -Werror
# ==================

# === Auto ===
SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
CCHF:=.cache_exists
# ============

# === Colors ===
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0m"
# ==============

all: $(NAME)

$(NAME): miniLibX/libmlx.a Libft/libft.a $(OBJ)
	@echo $(GREEN) "Compiling $@" $(EOC)
	@$(CC) $(LFLAGS) $(LIBFLAGS) $(OBJ) -o $@

miniLibX/libmlx.a:
	@echo $(CYAN) "Making $@" $(EOC)
	@make -C miniLibX

Libft/libft.a:
	@echo $(CYAN) "Making $@" $(EOC)
	@make -C Libft

$(CCHF):
	@mkdir $(CCHPATH)
	@touch $(CCHF)

$(CCHPATH)%.o: $(SRCPATH)%.c $(CCHF)
	@echo $(PURPLE) " - Compiling $< into $@" $(RED)
	@$(CC) $(CFLAGS) $(LFLAGS) -c $< -o $@

$(SRCPATH)%.c:
	@echo $(RED) "Missing File : $@" $(EOC)

norme:
	@echo $(RED)
	@norminette $(SRC) $(HDRPATH) | grep -v	Norme -B1 || true
	@echo $(END)

clean:
	@rm -rf $(CCHPATH)
	@rm -f $(CCHF)

fclean: clean
	@rm -f $(NAME)

test:
	@echo "Objects :" $(OBJ)
	@echo "Sources :" $(SRC)
	@echo "Files :" $(FILES)

re: fclean all
