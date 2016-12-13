#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 17:38:00 by angagnie          #+#    #+#              #
#    Updated: 2016/12/09 14:35:45 by angagnie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# ==== Editable ====
EXEC_NAME:=wolf3d
LIB_NAME:=libgg.a
# ------------------
MODEL:=geometry \
	matrices_mult matrices_axis matrices_axis4 matrices_misc \
	system_tree_add system_tree_del system_tree_new system_tree_misc \
	conversion_polar conversion_spher \
	quaternion_conj quaternion_misc quaternion_new quaternion_prod \
	quaternion_rotate quaternion_sum \
	complex_math complex_math2 complex_new
FILES=main debug
CORE=render reader parser ft_ator ggl_main misc view view_interpolate
DEFAULT=controller controller_mouse view_defaults
EDITOR=render_functions1 editor_controller editor_controller_mouse editor
WOLF=wolf_render wolf_main
FRACTAL=fractals_controller fractals_controller_mouse \
	fractals_main fractals_render fractals_functions fractals_misc
TSP=tsp_main
MODEL_PATH:=model/
CORE_PATH:=core/
DEFAULT_PATH:=defaults/
EDITOR_PATH:=editor/
WOLF_PATH:=wolf/
FRACTAL_PATH:=fractals/
TSP_PATH:=TSP/
LIBFT_PATH=Libft/
LIBFT_HDR=Libft/include/
# ==================

# ==== Standard ====
CC:=clang
LINKER:=ar rc
CCHPATH=cache/
SRCPATH=src/
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
FILES+=$(addprefix $(CORE_PATH),$(CORE))
FILES+=$(addprefix $(DEFAULT_PATH),$(DEFAULT))
FILES+=$(addprefix $(EDITOR_PATH),$(EDITOR))
FILES+=$(addprefix $(WOLF_PATH),$(WOLF))
FILES+=$(addprefix $(FRACTAL_PATH),$(FRACTAL))
FILES+=$(addprefix $(TSP_PATH),$(TSP))
FILES+=$(addprefix $(MODEL_PATH),$(MODEL))
SRC=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
OBJ=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
# ==================
CCHF:=.cache_exists

usage: all
	@echo $(WHITE) "Usage : make    < osx | x11 >    < all | re | clean | fclean | test >     [ debug ]" $(EOC)

all: osx $(EXEC_NAME)

$(EXEC_NAME): $(OBJ) $(DEP)
	@echo $(GREEN) " - Compiling $@" $(EOC)
	@$(CC) $(OBJ) -o $@ $(IFLAGS) $(LFLAGS)

$(LIB_NAME): $(OBJ) $(DEP)
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
	@mkdir $(CCHPATH)$(CORE_PATH)
	@mkdir $(CCHPATH)$(DEFAULT_PATH)
	@mkdir $(CCHPATH)$(EDITOR_PATH)
	@mkdir $(CCHPATH)$(WOLF_PATH)
	@mkdir $(CCHPATH)$(FRACTAL_PATH)
	@mkdir $(CCHPATH)$(TSP_PATH)
	@touch $(CCHF)

clean:
	@echo $(YELLOW) "Deleting cache" $(EOC)
	@rm -rf $(CCHPATH)
	@rm -f $(CCHF)

fclean: clean
	@echo $(YELLOW) "Deleting binairie" $(EOC)
	@rm -f $(NAME)
	@rm -f $(EXEC_NAME)
	@rm -rf $(EXEC_NAME).dSYM/

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
	$(eval DEFLAG=-DX11)
	$(eval LFLAGS+=-lX11)

osx:
	$(eval IFLAGS+=-I miniLibX_OSX/)
	$(eval LFLAGS+=-lmlx -framework OpenGL -framework AppKit)
	$(eval DEP+=miniLibX_OSX/libmlx.a)

debug:
	$(eval CFLAGS+=-g -DDEBUG)
	@echo $(CYAN)"Generating debug informations"$(EOC)
	@$(CC) $(CFLAGS) $(LFLAGS) -o $(EXEC_NAME) $(SRC)

lib: $(LIB_NAME)

.PHONY: all clean fclean re test norm x11 osx usage debug exec lib
