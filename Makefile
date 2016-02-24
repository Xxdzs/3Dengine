#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 17:38:00 by angagnie          #+#    #+#              #
#    Updated: 2016/01/13 13:52:07 by angagnie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# ==== Editable ====
NAME:=fdf
MODEL_PATH:=model/
MODEL:=calculus quaternion conversion
FILES:=main view controller
# ==================

# ==== Standard ====
CC:=clang
CCHPATH:=cache/
SRCPATH:=src/
HDRPATH:=include/
IFLAGS=-I $(HDRPATH) -I Libft/include/
DEFLAG=
LFLAGS=-L Libft/ -lft
CFLAGS=-Wall -Wextra $(IFLAGS) $(DEFLAG)
# ==================
IFLAGS+=-I miniLibX_OSX/
LFLAGS+=-lmlx -framework OpenGL -framework AppKit
# ==================

# === Colors ===
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
YELLOW:="\033[1;33m"
BLUE:="\033[1;34m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0m"
# ==============

# ====== Auto ======
FILES+=$(addprefix $(MODEL_PATH),$(MODEL))
SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
# ==================
CCHF:=.cache_exists

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(GREEN) " - Compiling $@" $(EOC)
	@$(CC) $< -o $@

$(CCHPATH)%.o: $(SRCPATH)%.c $(CCHF)
	@echo $(PURPLE) " - Compiling $< into $@" $(EOC)
	@$(CC) $(CFLAGS) -c $< -o $@

%.c:
	@echo $(RED) "Missing file : $@" $(EOC)

$(CCHF):
	@mkdir $(CCHPATH)
	@mkdir $(CCHPATH)$(MODEL_PATH)
	@touch $(CCHF)

clean:
	@rm -rf $(CCHPATH)
	@rm -f $(CCHF)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test:
	@echo "Files :" $(FILES)

norme:
	@echo $(RED)
	@norminette $(SRC) $(HDRPATH) | grep -v  Norme -B1 || true
	@echo $(END)

def_x11:
	$(eval DEFLAG=-DX11)

x11: def_x11 all

.PHONY: all clean fclean re test norme x11 def_x11
