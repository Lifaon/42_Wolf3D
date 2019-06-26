# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 22:00:00 by mlantonn          #+#    #+#              #
#    Updated: 2019/06/26 14:18:36 by mlantonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[31m
GRE = \033[32m
YEL = \033[33m
BLU = \033[34m
MAG = \033[35m
CYA = \033[36m
EOC = \033[39m

NAME = wolf3d
DIR_NAME = wolf3d

DIR_LIB = lib/
DIR_FT_PRINTF = $(DIR_LIB)ft_printf/

CFLAGS = #-Wall -Wextra -Werror

INCS = $(INC) $(INC_FT_PRINTF)
INC = -I includes/
INC_FT_PRINTF = -I $(DIR_FT_PRINTF)includes/

LIBS = $(LIB_FT_PRINTF)
LIB_FT_PRINTF = -L $(DIR_FT_PRINTF) -lftprintf

OBJS = $(SRCS:.c=.o)
OBJS_DIR = obj/
OBJS_SUB_DIRS =
OBJS_PRE = $(addprefix $(OBJS_DIR), $(OBJS))

SRCS_DIR = src/
SRCS =	main.c

.PHONY = all $(OBJS_DIR) $(NAME) clean fclean re debug re_debug change_cflag

all: $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@echo "gcc $(CFLAGS) $(INCS) -c $^ -o $(CYA)$@$(EOC)"
	@gcc $(CFLAGS) $(INCS) -c $^ -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@if [ "$(OBJS_SUB_DIRS)" != "" ]; then \
		mkdir -p $(addprefix $(OBJS_DIR)/, $(OBJS_SUB_DIRS)); \
	fi

$(NAME): $(OBJS_DIR) $(OBJS_PRE)
	@make -C $(DIR_FT_PRINTF)
	@echo "gcc $(CFLAGS) $(OBJS_PRE) $(LIBS) -o $(MAG)$(NAME)$(EOC)"
	@gcc $(CFLAGS) $(OBJS_PRE) $(LIBS) -o $(NAME)

clean:
	@make clean -C $(DIR_FT_PRINTF)
	@echo "$(RED)rm -rf$(EOC) $(OBJS_DIR) from $(DIR_NAME)"
	@rm -rf $(OBJS_DIR)

fclean: clean
	@make fclean -C $(DIR_FT_PRINTF)
	@echo "$(RED)rm -rf$(EOC) $(NAME)"
	@rm -rf $(NAME)

re: fclean all

# debug rules

debug: change_cflag all

re_debug: fclean debug

change_cflag:
	@$(eval CFLAGS = -fsanitize=address)
