#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 17:38:00 by angagnie          #+#    #+#              #
#    Updated: 2016/03/31 10:31:18 by angagnie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# ==== Editable ====
EXEC_NAME:=ggl
NAME:=libgg.a
MODEL_PATH:=model/
MODEL:=quaternion conversion matrices system_tree
FILES=view controller render parser ft_ator
LIBFT_PATH=../Libft/
LIBFT_HDR=../Libft/include/
# ==================

# ==== Standard ====
CC:=clang
LINKER:=ar rc
CCHPATH:=cache/
SRCPATH:=src/
HDRPATH:=include/
IFLAGS=-I $(HDRPATH) -I $(LIBFT_HDR)
DEFLAG=
LFLAGS=-L $(LIBFT_PATH) -lft
DEP=$(LIBFT_PATH)libft.a
CFLAGS=-Wall -Wextra $(IFLAGS) $(DEFLAG)
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
FILES+=$(MAIN)
FILES+=$(addprefix $(MODEL_PATH),$(MODEL))
SRC=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
OBJ=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
# ==================
CCHF:=.cache_exists

usage: osx all debug
	@echo $(WHITE) "Usage : make    < osx | x11 >    < all | re | clean | fclean | test >     [ debug ]" $(EOC)

all: $(NAME) $(EXEC_NAME)

exec: $(EXEC_NAME)

$(EXEC_NAME): $(OBJ) $(DEP)
	@echo $(GREEN) " - Compiling $@" $(EOC)
	@$(CC) $(OBJ) -o $@ $(IFLAGS) $(LFLAGS)

$(NAME): $(OBJ) $(DEP)
	@echo $(GREEN) " - Compiling $@" $(EOC)
	@$(LINKER) $@ $(OBJ)
	@ranlib $@

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
	@echo $(YELLOW) "Deleting cache" $(EOC)
	@rm -rf $(CCHPATH)
	@rm -f $(CCHF)

fclean: clean
	@echo $(YELLOW) "Deleting binairie" $(EOC)
	@rm -f $(NAME)
	@rm -f $(EXEC_NAME)
	@rm -rf $(NAME).dSYM/

re: fclean all

test:
	@echo $(YELLOW)"Files :\n\033[0;33m"$(FILES)
	@echo $(BLUE)"Objects :\n\033[0;34m"$(OBJ)
	@echo $(CYAN)"Sources :\n\033[0;36m"$(SRC)$(EOC)
	@echo "Include flags :" $(IFLAGS)
	@echo "Defined flags :" $(DEFLAG)
	@echo "Librairies flags :" $(LFLAGS)
	@echo "Dependencies :" $(DEP)
	@echo "Compilation flags :" $(CFLAGS)

norm:
	@echo $(RED)
	norminette $(SRC) $(HDRPATH) | grep -v  Norme -B1 || true
	@echo $(END)

$(LIBFT_PATH)libft.a:
	@echo $(BLUE) "Making $@" $(EOC)
	@make -C Libft/
	@make -C Libft clean

miniLibX_OSX/libmlx.a:
	@echo $(BLUE) "Making $@" $(EOC)
	@make -C miniLibX_OSX/

x11:
	$(eval FILES+=ggl_main_x11)
	$(eval DEFLAG=-DX11)
	$(eval LFLAGS+=-lX11)

osx:
	$(eval FILES+=ggl_main_osx)
	$(eval IFLAGS+=-I miniLibX_OSX/)
	$(eval LFLAGS+=-lmlx -framework OpenGL -framework AppKit)
	$(eval DEP+=miniLibX_OSX/libmlx.a)

debug:
	$(eval CFLAGS+=-g)
	@echo $(CYAN)"Generating debug informations"$(EOC)
	@$(CC) $(CFLAGS) $(LFLAGS) -o $(EXEC_NAME) $(SRC)

.PHONY: all clean fclean re test norme x11 osx usage debug exec
