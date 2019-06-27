# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 22:00:00 by mlantonn          #+#    #+#              #
#    Updated: 2019/06/27 14:57:10 by mlantonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL				:=			all

NAME						:=			wolf3d
DIR_NAME					:=			wolf3d

#==============================================================================#
#------------------------------------------------------------------------------#
#                                 COLOR                                        #

RED							:=			\033[31m
GRE							:=			\033[32m
YEL							:=			\033[33m
BLU							:=			\033[34m
MAG							:=			\033[35m
CYA							:=			\033[36m
EOC							:=			\033[39m

#==============================================================================#
#------------------------------------------------------------------------------#
#                               DIRECTORIES                                    #

INC_DIR						:=			includes/
OBJS_DIR					:=			obj/

#==============================================================================#
#------------------------------------------------------------------------------#
#                            COMPILER & FLAGS                                  #

CC							:=			gcc
CFLAGS						:=			-Wall -Wextra -Werror

# Can use this with cmd: `env DEV make`
ifneq ($(DEBUG),)
OBJS_DIR					:=			debug/
CFLAGS						+=			-g3
else
  ifneq ($(DEV),)
  OBJS_DIR					:=			dev/
  CFLAGS					+=			-g3
  CFLAGS					+=			-O0 -std=c99 \
  										-Wchar-subscripts -Wparentheses \
										-Wsequence-point -Winline \
										-Wdisabled-optimization
  endif
endif

#==============================================================================#
#------------------------------------------------------------------------------#
#                                   LIBRARIES                                  #

DIR_LIB						:=			lib/
INCS						:=			-I$(INC_DIR)
LIBS						:=

#---------------#
#   FT_PRINTF   #

DIR_FT_PRINTF				:=			$(DIR_LIB)ft_printf/
LIB_FT_PRINTF				:=			-L $(DIR_FT_PRINTF) -lftprintf
LIBS						+=			$(LIB_FT_PRINTF)

#----------#
#   SDL2   #

DIR_SDL2					:=			$(DIR_LIB)sdl2
SDL_VER						:=			2.0.9
SDL_PATH					:=			$(addprefix $(shell pwd)/, $(DIR_SDL2))

ifneq ($(wildcard $(DIR_SDL2)),)
  LIB_SDL2					:=			$(shell sh $(DIR_SDL2)/bin/sdl2-config --libs)
  LIBS						+=			$(LIB_SDL2)

  INC_SDL2					:=			$(shell sh $(DIR_SDL2)/bin/sdl2-config --cflags)
  INCS						+=			$(INC_SDL2)
endif

#==============================================================================#
#------------------------------------------------------------------------------#
#                                  FILES                                       #

#-----------#
#    ROOT   #

SRCS_DIR					:=			src/

INCS_NAME					:=			wolf3d.h

SRCS_NAME					:=			main.c

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(addprefix $(SRCS_DIR),$(INCS_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@echo "$(MAG)$(NAME)$(EOC) :: $(CC) $(CFLAGS) $(INCS) -c $< -o $(CYA)$@$(EOC)"

OBJS						:=			$(addprefix $(OBJS_DIR),$(SRCS_NAME:.c=.o))

OBJS_SUB_DIRS				:=			OBJS_PRE := $(addprefix $(OBJS_DIR), $(OBJS))
ALL_OBJS_SUB_DIRS			:=

#-----------#
#   PARSER  #

SRCS_PARSER_DIR				:=			parser/
PATH_PARSER					:=			$(SRCS_DIR)$(SRCS_PARSER_DIR)


INCS_PARSER_NAME			:=			parser.h

SRCS_PARSER_NAME			:=			parse_wolf_map.c

ALL_OBJS_SUB_DIRS			+=			$(OBJS_DIR)$(SRCS_PARSER_DIR)
OBJS						+=			$(addprefix $(OBJS_DIR)$(SRCS_PARSER_DIR),$(SRCS_PARSER_NAME:.c=.o))

$(OBJS_DIR)$(SRCS_PARSER_DIR)%.o: $(PATH_PARSER)%.c $(addprefix $(PATH_PARSER),$(INCS_PARSER_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@echo "$(MAG)$(NAME)$(EOC) :: $(CC) $(CFLAGS) $(INCS) -c $< -o $(CYA)$@$(EOC)"

#-----------#
#   UTILS   #

SRCS_UTILS_DIR				:=			utils/

INCS_UTILS_NAME				:=			wutils.h

SRCS_UTILS_NAME				:=			read_file.c

ALL_OBJS_SUB_DIRS			+=			$(OBJS_DIR)$(SRCS_UTILS_DIR)
OBJS						+=			$(addprefix $(OBJS_DIR)$(SRCS_UTILS_DIR),$(SRCS_UTILS_NAME:.c=.o))

$(OBJS_DIR)$(SRCS_UTILS_DIR)%.o: $(PATH_UTILS)%.c $(addprefix $(PATH_UTILS),$(INCS_UTILS_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@echo "$(MAG)$(NAME)$(EOC) :: $(CC) $(CFLAGS) $(INCS) -c $< -o $(CYA)$@$(EOC)"


.PHONY: all clean fclean re debug re_debug change_cflag sdl2

test_inc:
	@echo $(INCS)

all: $(NAME)

# rule to create object dir

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(ALL_OBJS_SUB_DIRS)

# rule to compile wolf3d

$(NAME): $(OBJS_DIR) $(OBJS)
	@$(MAKE) -C $(DIR_FT_PRINTF)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(MAG)$(NAME)$(EOC)"

# cleaning rules

clean:
	@$(MAKE) clean -C $(DIR_FT_PRINTF)
	@echo "$(RED)rm -rf$(EOC) $(OBJS_DIR) from $(DIR_NAME)"
	@rm -rf $(OBJS_DIR)

fclean:
	@$(MAKE) fclean -C $(DIR_FT_PRINTF)
	@echo "$(RED)rm -rf$(EOC) $(OBJS_DIR) from $(DIR_NAME)"
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)rm -rf$(EOC) $(NAME)"
	@rm -rf $(NAME)

re: fclean all

# debug rules

debug: change_cflag all

re_debug: fclean debug

change_cflag:
	@$(eval CFLAGS = -fsanitize=address)

# rule to recreate includes folder

$(INC_DIR):
	@rm -rf includes && mkdir includes && find . -name "*.h" -exec ln -s .{} includes \;
	@echo "Recreated $(MAG)$(INC_DIR)$(EOC) folder"

# rule to compile sdl2

sdl2:
	@if [ ! -d "./lib/sdl2" ]; then \
		echo "Installing $(YEL)SDL2-$(SDL_VER)$(EOC) ..."; \
		printf "In 3 ..."; sleep 1; \
		printf "\rIn 2 ..."; sleep 1; \
		printf "\rIn 1 ..."; sleep 1; printf "\r"; \
		curl -OL http://www.libsdl.org/release/SDL2-$(SDL_VER).tar.gz && \
		tar -zxvf SDL2-$(SDL_VER).tar.gz && \
		rm SDL2-$(SDL_VER).tar.gz && \
		mkdir -p $(SDL_PATH) && \
		cd SDL2-$(SDL_VER) && \
			sh configure --prefix=$(SDL_PATH) && \
			make && \
			make install && \
		cd .. && \
		rm -rf SDL2-$(SDL_VER); \
		echo "$(YEL)SDL2-$(SDL_VER)$(EOC) was successfully installed"; \
	else \
		echo "$(YEL)SDL2-$(SDL_VER)$(EOC) already installed"; \
	fi
