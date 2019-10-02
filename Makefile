# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 22:00:00 by mlantonn          #+#    #+#              #
#    Updated: 2019/10/01 10:53:37 by mlantonn         ###   ########.fr        #
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

# Can use this with cmd: `env DEV=1 make`
ifneq ($(DEBUG),)
OBJS_DIR					:=			debug/
CFLAGS						+=			-g3 -fsanitize=address
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

LIB_FT_PRINTF				:=			-L$(DIR_FT_PRINTF) -lftprintf
LIBS						+=			$(LIB_FT_PRINTF)

INC_FT_PRINTF				:=			-I$(DIR_FT_PRINTF)includes
INCS						+=			$(INC_FT_PRINTF)

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

SRCS_NAME					:=			main.c						\

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(addprefix $(SRCS_DIR),$(INCS_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@echo "$(MAG)$(NAME)$(EOC) :: $(CC) $(CFLAGS) $(INCS) -c $< -o $(CYA)$@$(EOC)"

OBJS						:=			$(addprefix $(OBJS_DIR),$(SRCS_NAME:.c=.o))

OBJS_SUB_DIRS				:=			OBJS_PRE := $(addprefix $(OBJS_DIR), $(OBJS))
ALL_OBJS_SUB_DIRS			:=

#-----------#
#   MYSDL   #

SRCS_MYSDL_DIR				:=			mysdl/
PATH_MYSDL					:=			$(SRCS_DIR)$(SRCS_MYSDL_DIR)

INCS_MYSDL_NAME				:=			mysdl.h						\

SRCS_MYSDL_NAME				:=			utils.c						\
										load_image.c				\

ALL_OBJS_SUB_DIRS			+=			$(OBJS_DIR)$(SRCS_MYSDL_DIR)
OBJS						+=			$(addprefix $(OBJS_DIR)$(SRCS_MYSDL_DIR),$(SRCS_MYSDL_NAME:.c=.o))

$(OBJS_DIR)$(SRCS_MYSDL_DIR)%.o: $(PATH_MYSDL)%.c $(addprefix $(PATH_MYSDL),$(INCS_MYSDL_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@echo "$(MAG)$(NAME)$(EOC) :: $(CC) $(CFLAGS) $(INCS) -c $< -o $(CYA)$@$(EOC)"

#-----------#
#    DATA   #

SRCS_DATA_DIR				:=			data/
PATH_DATA					:=			$(SRCS_DIR)$(SRCS_DATA_DIR)

#	BLOCK

SRCS_BLOCK_DIR				:=			block/
PATH_BLOCK					:=			$(PATH_DATA)$(SRCS_BLOCK_DIR)


INCS_BLOCK_NAME				:=			block.h

SRCS_BLOCK_NAME				:=			block_del.c					\
										block_get.c					\
										block_new.c					\
										block_parse.c				\
										block_parse_pairs.c			\
										block_length.c				\

ALL_OBJS_SUB_DIRS			+=			$(OBJS_DIR)$(SRCS_DATA_DIR)$(SRCS_BLOCK_DIR)
OBJS						+=			$(addprefix $(OBJS_DIR)$(SRCS_DATA_DIR)$(SRCS_BLOCK_DIR),$(SRCS_BLOCK_NAME:.c=.o))

$(OBJS_DIR)$(SRCS_DATA_DIR)$(SRCS_BLOCK_DIR)%.o: $(PATH_BLOCK)%.c $(addprefix $(PATH_BLOCK),$(INCS_BLOCK_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@echo "$(MAG)$(NAME)$(EOC) :: $(CC) $(CFLAGS) $(INCS) -c $< -o $(CYA)$@$(EOC)"

#	ENV

SRCS_ENV_DIR				:=			env/
PATH_ENV					:=			$(PATH_DATA)$(SRCS_ENV_DIR)


INCS_ENV_NAME				:=			env.h

SRCS_ENV_NAME				:=			env_del.c					\
										env_new.c					\
										env_get.c					\
										env_parse.c					\
										env_length.c				\

ALL_OBJS_SUB_DIRS			+=			$(OBJS_DIR)$(SRCS_DATA_DIR)$(SRCS_ENV_DIR)
OBJS						+=			$(addprefix $(OBJS_DIR)$(SRCS_DATA_DIR)$(SRCS_ENV_DIR),$(SRCS_ENV_NAME:.c=.o))

$(OBJS_DIR)$(SRCS_DATA_DIR)$(SRCS_ENV_DIR)%.o: $(PATH_ENV)%.c $(addprefix $(PATH_ENV),$(INCS_ENV_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@echo "$(MAG)$(NAME)$(EOC) :: $(CC) $(CFLAGS) $(INCS) -c $< -o $(CYA)$@$(EOC)"

#	MAP

SRCS_MAP_DIR				:=			map/
PATH_MAP					:=			$(PATH_DATA)$(SRCS_MAP_DIR)


INCS_MAP_NAME				:=			map.h

SRCS_MAP_NAME				:=			map_del.c					\
										map_new.c					\
										map_parse.c					\
										map_length.c				\

ALL_OBJS_SUB_DIRS			+=			$(OBJS_DIR)$(SRCS_DATA_DIR)$(SRCS_MAP_DIR)
OBJS						+=			$(addprefix $(OBJS_DIR)$(SRCS_DATA_DIR)$(SRCS_MAP_DIR),$(SRCS_MAP_NAME:.c=.o))

$(OBJS_DIR)$(SRCS_DATA_DIR)$(SRCS_MAP_DIR)%.o: $(PATH_MAP)%.c $(addprefix $(PATH_MAP),$(INCS_MAP_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@echo "$(MAG)$(NAME)$(EOC) :: $(CC) $(CFLAGS) $(INCS) -c $< -o $(CYA)$@$(EOC)"

#	SINGLETONE

SRCS_SINGLETONE_DIR			:=			singletone/
PATH_SINGLETONE				:=			$(PATH_DATA)$(SRCS_SINGLETONE_DIR)


INCS_SINGLETONE_NAME		:=			singletone.h

SRCS_SINGLETONE_NAME		:=			singletone_block.c			\
										singletone_env.c			\
										singletone_map.c			\
										singletone_texture.c		\

ALL_OBJS_SUB_DIRS			+=			$(OBJS_DIR)$(SRCS_DATA_DIR)$(SRCS_SINGLETONE_DIR)
OBJS						+=			$(addprefix $(OBJS_DIR)$(SRCS_DATA_DIR)$(SRCS_SINGLETONE_DIR),$(SRCS_SINGLETONE_NAME:.c=.o))

$(OBJS_DIR)$(SRCS_DATA_DIR)$(SRCS_SINGLETONE_DIR)%.o: $(PATH_SINGLETONE)%.c $(addprefix $(PATH_SINGLETONE),$(INCS_SINGLETONE_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@echo "$(MAG)$(NAME)$(EOC) :: $(CC) $(CFLAGS) $(INCS) -c $< -o $(CYA)$@$(EOC)"



#	TEXTURE

SRCS_TEXTURE_DIR			:=			texture/
PATH_TEXTURE				:=			$(PATH_DATA)$(SRCS_TEXTURE_DIR)


INCS_TEXTURE_NAME			:=			texture.h

SRCS_TEXTURE_NAME			:=			texture_del.c				\
										texture_load.c				\
										texture_new.c				\
										texture_parse.c				\
										texture_get_color.c			\
										texture_length.c			\

ALL_OBJS_SUB_DIRS			+=			$(OBJS_DIR)$(SRCS_DATA_DIR)$(SRCS_TEXTURE_DIR)
OBJS						+=			$(addprefix $(OBJS_DIR)$(SRCS_DATA_DIR)$(SRCS_TEXTURE_DIR),$(SRCS_TEXTURE_NAME:.c=.o))

$(OBJS_DIR)$(SRCS_DATA_DIR)$(SRCS_TEXTURE_DIR)%.o: $(PATH_TEXTURE)%.c $(addprefix $(PATH_TEXTURE),$(INCS_TEXTURE_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@echo "$(MAG)$(NAME)$(EOC) :: $(CC) $(CFLAGS) $(INCS) -c $< -o $(CYA)$@$(EOC)"

#	TEXTURE		LOADED

SRCS_TEXTURE_LOADED_DIR		:=			loaded/
PATH_TEXTURE_LOADED			:=			$(PATH_TEXTURE)$(SRCS_TEXTURE_LOADED_DIR)


INCS_TEXTURE_LOADED_NAME	:=			loaded.h

SRCS_TEXTURE_LOADED_NAME	:=			loaded_del.c				\
										loaded_load.c				\
										loaded_new.c				\
										loaded_get_color.c			\

ALL_OBJS_SUB_DIRS			+=			$(OBJS_DIR)$(SRCS_DATA_DIR)$(SRCS_TEXTURE_DIR)$(SRCS_TEXTURE_LOADED_DIR)
OBJS						+=			$(addprefix $(OBJS_DIR)$(SRCS_DATA_DIR)$(SRCS_TEXTURE_DIR)$(SRCS_TEXTURE_LOADED_DIR),$(SRCS_TEXTURE_LOADED_NAME:.c=.o))

$(OBJS_DIR)$(SRCS_DATA_DIR)$(SRCS_TEXTURE_DIR)$(SRCS_TEXTURE_LOADED_DIR)%.o: $(PATH_TEXTURE_LOADED)%.c $(addprefix $(PATH_TEXTURE_LOADED),$(INCS_TEXTURE_LOADED_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@echo "$(MAG)$(NAME)$(EOC) :: $(CC) $(CFLAGS) $(INCS) -c $< -o $(CYA)$@$(EOC)"

#	TEXTURE		SG

SRCS_TEXTURE_SG_DIR			:=			sg/
PATH_TEXTURE_SG				:=			$(PATH_TEXTURE)$(SRCS_TEXTURE_SG_DIR)

INCS_TEXTURE_SG_NAME		:=			sg.h

SRCS_TEXTURE_SG_NAME		:=			sg_del.c				\
										sg_load.c				\
										sg_new.c				\
										sg_get_color.c			\

ALL_OBJS_SUB_DIRS			+=			$(OBJS_DIR)$(SRCS_DATA_DIR)$(SRCS_TEXTURE_DIR)$(SRCS_TEXTURE_SG_DIR)
OBJS						+=			$(addprefix $(OBJS_DIR)$(SRCS_DATA_DIR)$(SRCS_TEXTURE_DIR)$(SRCS_TEXTURE_SG_DIR),$(SRCS_TEXTURE_SG_NAME:.c=.o))

$(OBJS_DIR)$(SRCS_DATA_DIR)$(SRCS_TEXTURE_DIR)$(SRCS_TEXTURE_SG_DIR)%.o: $(PATH_TEXTURE_SG)%.c $(addprefix $(PATH_TEXTURE_SG),$(INCS_TEXTURE_SG_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@echo "$(MAG)$(NAME)$(EOC) :: $(CC) $(CFLAGS) $(INCS) -c $< -o $(CYA)$@$(EOC)"

#-----------#
#   PARSER  #

SRCS_PARSER_DIR				:=			parser/
PATH_PARSER					:=			$(SRCS_DIR)$(SRCS_PARSER_DIR)

INCS_PARSER_NAME			:=			parser.h

SRCS_PARSER_NAME			:=			parse_wolf_map.c			\

ALL_OBJS_SUB_DIRS			+=			$(OBJS_DIR)$(SRCS_PARSER_DIR)
OBJS						+=			$(addprefix $(OBJS_DIR)$(SRCS_PARSER_DIR),$(SRCS_PARSER_NAME:.c=.o))

$(OBJS_DIR)$(SRCS_PARSER_DIR)%.o: $(PATH_PARSER)%.c $(addprefix $(PATH_PARSER),$(INCS_PARSER_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@echo "$(MAG)$(NAME)$(EOC) :: $(CC) $(CFLAGS) $(INCS) -c $< -o $(CYA)$@$(EOC)"

#	WAT_PARSER

SRCS_WAT_PARSER_DIR			:=			wat_parse/
PATH_WAT_PARSER				:=			$(PATH_PARSER)$(SRCS_WAT_PARSER_DIR)


INCS_WAT_PARSER_NAME		:=			wat_parse.h

SRCS_WAT_PARSER_NAME		:=			wat_parse.c					\
										wat_element_match.c			\

ALL_OBJS_SUB_DIRS			+=			$(OBJS_DIR)$(SRCS_PARSER_DIR)$(SRCS_WAT_PARSER_DIR)
OBJS						+=			$(addprefix $(OBJS_DIR)$(SRCS_PARSER_DIR)$(SRCS_WAT_PARSER_DIR),$(SRCS_WAT_PARSER_NAME:.c=.o))

$(OBJS_DIR)$(SRCS_PARSER_DIR)$(SRCS_WAT_PARSER_DIR)%.o: $(PATH_WAT_PARSER)%.c $(addprefix $(PATH_WAT_PARSER),$(INCS_WAT_PARSER_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@echo "$(MAG)$(NAME)$(EOC) :: $(CC) $(CFLAGS) $(INCS) -c $< -o $(CYA)$@$(EOC)"

#	DICTO

SRCS_DICTO_DIR				:=			dicto/
PATH_DICTO					:=			$(PATH_PARSER)$(SRCS_DICTO_DIR)


INCS_DICTO_NAME				:=			dicto.h

SRCS_DICTO_NAME				:=			dicto.c						\

ALL_OBJS_SUB_DIRS			+=			$(OBJS_DIR)$(SRCS_PARSER_DIR)$(SRCS_DICTO_DIR)
OBJS						+=			$(addprefix $(OBJS_DIR)$(SRCS_PARSER_DIR)$(SRCS_DICTO_DIR),$(SRCS_DICTO_NAME:.c=.o))

$(OBJS_DIR)$(SRCS_PARSER_DIR)$(SRCS_DICTO_DIR)%.o: $(PATH_DICTO)%.c $(addprefix $(PATH_DICTO),$(INCS_DICTO_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@echo "$(MAG)$(NAME)$(EOC) :: $(CC) $(CFLAGS) $(INCS) -c $< -o $(CYA)$@$(EOC)"

#----------------#
#   RAYCASTING   #

SRCS_RAYCASTING_DIR				:=		raycasting/
PATH_RAYCASTING					:=		$(SRCS_DIR)$(SRCS_RAYCASTING_DIR)

INCS_RAYCASTING_NAME			:=		raycasting.h					\

SRCS_RAYCASTING_NAME			:=		raycasting.c					\
										process_ray.c						\
										draw_line.c						\
										vec_op.c						\

ALL_OBJS_SUB_DIRS			+=			$(OBJS_DIR)$(SRCS_RAYCASTING_DIR)
OBJS						+=			$(addprefix $(OBJS_DIR)$(SRCS_RAYCASTING_DIR),$(SRCS_RAYCASTING_NAME:.c=.o))

$(OBJS_DIR)$(SRCS_RAYCASTING_DIR)%.o: $(PATH_RAYCASTING)%.c $(addprefix $(PATH_RAYCASTING),$(INCS_RAYCASTING_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@echo "$(MAG)$(NAME)$(EOC) :: $(CC) $(CFLAGS) $(INCS) -c $< -o $(CYA)$@$(EOC)"

#------------#
#   EVENTS   #

SRCS_EVENTS_DIR					:=		events/
PATH_EVENTS						:=		$(SRCS_DIR)$(SRCS_EVENTS_DIR)

INCS_EVENTS_NAME				:=		events.h					\

SRCS_EVENTS_NAME				:=		events.c					\
										update_cam.c				\
										key_events.c				\
										mouse_events.c				\
										window_events.c				\

ALL_OBJS_SUB_DIRS				+=			$(OBJS_DIR)$(SRCS_EVENTS_DIR)
OBJS							+=			$(addprefix $(OBJS_DIR)$(SRCS_EVENTS_DIR),$(SRCS_EVENTS_NAME:.c=.o))

$(OBJS_DIR)$(SRCS_EVENTS_DIR)%.o: $(PATH_EVENTS)%.c $(addprefix $(PATH_EVENTS),$(INCS_EVENTS_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@echo "$(MAG)$(NAME)$(EOC) :: $(CC) $(CFLAGS) $(INCS) -c $< -o $(CYA)$@$(EOC)"

#-----------#
#   UTILS   #

SRCS_UTILS_DIR				:=			utils/
PATH_UTILS					:=			$(SRCS_DIR)$(SRC_UTILS_DIR)

INCS_UTILS_NAME				:=			wutils.h

SRCS_UTILS_NAME				:=			ft_atoul_base.c				\
										ft_getline.c				\
										ft_memcmp.c					\
										ft_memcpy.c					\
										ft_memmove.c				\
										ft_memset.c					\
										ft_str2del.c				\
										ft_strcdup.c				\
										ft_strchr.c					\
										ft_strdup.c					\
										ft_strlen.c					\
										ft_strncmp.c				\
										is_pow_of2.c				\
										prepare_template.c			\
										read_file.c					\
										read_file2d.c				\
										round_up_pow.c				\

ALL_OBJS_SUB_DIRS			+=			$(OBJS_DIR)$(SRCS_UTILS_DIR)
OBJS						+=			$(addprefix $(OBJS_DIR)$(SRCS_UTILS_DIR),$(SRCS_UTILS_NAME:.c=.o))

$(OBJS_DIR)$(SRCS_UTILS_DIR)%.o: $(PATH_UTILS)%.c $(addprefix $(PATH_UTILS),$(INCS_UTILS_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@echo "$(MAG)$(NAME)$(EOC) :: $(CC) $(CFLAGS) $(INCS) -c $< -o $(CYA)$@$(EOC)"

#   ARRAY

SRCS_ARRAY_DIR				:=			array/
PATH_ARRAY					:=			$(PATH_UTILS)$(SRCS_ARRAY_DIR)

INCS_ARRAY_NAME				:=			array.h						\

SRCS_ARRAY_NAME				:=			array_delete.c				\
										array_find.c				\
										array_find_index.c			\
										array_foreach.c				\
										array_map.c					\
										array_new.c					\
										array_push.c				\
										array_push_at.c				\
										array_realloc.c				\
										array_show.c				\

ALL_OBJS_SUB_DIRS			+=			$(OBJS_DIR)$(SRCS_UTILS_DIR)$(SRCS_ARRAY_DIR)
OBJS						+=			$(addprefix $(OBJS_DIR)$(SRCS_UTILS_DIR)$(SRCS_ARRAY_DIR),$(SRCS_ARRAY_NAME:.c=.o))

$(OBJ_DIR)$(SRC_UTILS_DIR)$(SRCS_ARRAY_DIR)%.o: $(PATH_ARRAY)%.c $(addprefix $(PATH_ARRAY),$(INCS_ARRAY_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)
	@printf "${C_C}%s${C_X} :: ${C_R}%s${C_X}\n"  $(NAME) $@

#   PAIR

SRCS_PAIR_DIR				:=			pair/
PATH_PAIR					:=			$(PATH_UTILS)$(SRCS_PAIR_DIR)

INCS_PAIR_NAME				:=			pair.h						\

SRCS_PAIR_NAME				:=			pair_delete.c				\
										pair_get.c					\
										pair_key_new.c				\
										pair_new.c					\
										pair_parse.c				\
										pair_value_new.c			\

ALL_OBJS_SUB_DIRS			+=			$(OBJS_DIR)$(SRCS_UTILS_DIR)$(SRCS_PAIR_DIR)
OBJS						+=			$(addprefix $(OBJS_DIR)$(SRCS_UTILS_DIR)$(SRCS_PAIR_DIR),$(SRCS_PAIR_NAME:.c=.o))

$(OBJ_DIR)$(SRC_UTILS_DIR)$(SRCS_PAIR_DIR)%.o: $(PATH_PAIR)%.c $(addprefix $(PATH_PAIR),$(INCS_PAIR_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)
	@printf "${C_C}%s${C_X} :: ${C_R}%s${C_X}\n"  $(NAME) $@

#==============================================================================#
#------------------------------------------------------------------------------#
#                                  RULES                                       #

.PHONY: all clean fclean re debug re_debug change_cflag sdl2 $(INC_DIR)

test_inc:
	@echo $(INCS)

all: $(NAME)

# rule to create object dir

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(ALL_OBJS_SUB_DIRS):
	@mkdir -p $(ALL_OBJS_SUB_DIRS)

# rule to compile wolf3d

$(NAME): $(OBJS_DIR) $(ALL_OBJS_SUB_DIRS) $(OBJS)
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
	@rm -rf includes && mkdir includes && find src -name "*.h" -exec ln -s ../{} includes \;
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
