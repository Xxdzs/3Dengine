#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/16 12:17:30 by angagnie          #+#    #+#              #
#    Updated: 2016/02/23 20:09:39 by angagnie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# === Editable ===
NAME:=fdf
FILES:=main view controller
MODEL:=calculus conversion quaternion
# ================
MODEL_PATH:=model/
# ================

# ==== Standard ====
CC:=clang
CCHPATH:=cache/
SRCPATH:=src/
HDRPATH:=include/
LFLAGS:=-I $(HDRPATH) -I Libft/include/
LIBFLAGS:=-lmlx -framework OpenGL -framework AppKit -L Libft/ -lft
CFLAGS:=-Wall -Wextra
# ==================

# === Auto ===
FILES+=$(addprefix $(MODEL_PATH),$(MODEL))
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

osx: miniLibX_OSX/libmlx.a

x11: miniLibX_X11/libmlx.a

$(NAME): Libft/libft.a $(OBJ)
	@echo $(GREEN) "Compiling $@" $(EOC)
	@$(CC) $(LFLAGS) $(LIBFLAGS) $(OBJ) -o $@

miniLibX_OSX/libmlx.a:
	@echo $(CYAN) "Making $@" $(EOC)
	@make -C miniLibX_OSX

miniLibX_X11/libmlx.a:
	@echo $(CYAN) "Making $@" $(EOC)
	@make -C miniLibX_X11

Libft/libft.a:
	@echo $(CYAN) "Making $@" $(EOC)
	@make -C Libft

$(CCHF):
	@mkdir $(CCHPATH)
	@mkdir $(CCHPATH)$(MODEL_PATH)
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

.PHONY: re test fclean clean norme all osx x11
