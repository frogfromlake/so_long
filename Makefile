# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 18:21:35 by fquist            #+#    #+#              #
#    Updated: 2022/01/20 21:09:20 by fquist           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long

CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra -g
################################################################################
BONUS_SRCS		:= 1_main.c 2_create_window.c 3_errors.c 4_errors_2.c 5_init_map_struct.c \
			    6_init_player_struct.c 8_create_map.c 9_parser.c \
			    10_movement.c 11_hooks.c 12_animations.c 13_animation_utils.c \
			    14_win_or_lose.c 7_init_enemy_struct.c

SRCS			:= 1_main.c 2_create_window.c 3_errors.c 4_errors_2.c 5_init_map_struct.c \
			    6_init_player_struct.c 7_create_map.c 8_parser.c \
			    9_movement.c 10_hooks.c 11_animations.c 12_animation_utils.c \
			    13_win_or_lose.c

ODIR		:= obj
BONUS_ODIR	:= ../obj
SDIR		:= .
BONUS_SDIR	:= ./bonus_src
################################################################################
OBJS		= $(addprefix $(ODIR)/, $(SRCS:.c=.o))
BONUS_OBJS	= $(addprefix $(BONUS_ODIR)/, $(BONUS_SRCS:.c=.o))
INCLUDES	= -I./0_libft/inc -I./mlx

# COLORS
LB   		= \033[0;36m
B			= \033[0;34m
G		    = \033[0;32m
R 			= \033[0;31m
Y  			= \033[0;33m
X		    = \033[m

# **************************************************************************** #
#	SYSTEM SPECIFIC SETTINGS							   					   #
# **************************************************************************** #

UNAME_S		:= $(shell uname -s)

ifeq ($(UNAME_S), Linux)
	CFLAGS += -D LINUX -Wno-unused-result
endif

# **************************************************************************** #
#	RULES																	   #
# **************************************************************************** #

.PHONY: all $(NAME) header clean fclean re bonus debug release libft mlx

all: libft mlx $(NAME)

$(ODIR)/%.o: */%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "%-61b %b" "$(B)compiling: $(LB)$@" "$(G)[✓]$(X)\n"

$(NAME): prep $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -L0_libft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@printf "%-54b %b" "$(G)So_long compiled successfully!" "$(G)[✓]$(X)\n"
	@printf "$(B)===================== $(LB)$(NAME)$(B) =====================$(X)\n"

libft:
	@make -C 0_libft

mlx:
	@make -C mlx

bonus:
	@make -C src/bonus_src

header:
	@printf "$(B)===================== $(LB)$(NAME)$(B) =====================$(X)\n"

prep:
	@mkdir -p $(ODIR)

clean:
	@$(RM) -r *.dSYM $(SDIR)/*.dSYM $(SDIR)/$(NAME) $(ODIR)
	@make clean -C src/bonus_src/
	@make clean -C 0_libft
	@make clean -C mlx
	@printf "%-54b %b" "$(R)So_long cleaned!" "$(G)[✓]$(X)\n"
	@printf "%-54b %b" "$(R)libft cleaned!" "$(G)[✓]$(X)\n"
	@printf "%-54b %b" "$(R)minilibx cleaned!" "$(G)[✓]$(X)\n"

fclean: header clean
	@$(RM) $(NAME)
	@make clean -C mlx
	@make fclean -C 0_libft
	@printf "%-54b %b" "$(R)so_long fcleaned!" "$(G)[✓]$(X)\n"
	@printf "$(B)===================================================$(X)\n"

re: header fclean all

norm:
	@norminette -R CheckForbiddenSourceHeader src/*.c | grep --color=always 'Error!\|Error:' || echo "$(G)Everything is OK!$(X)" >&1

libnorm:
	@norminette -R CheckForbiddenSourceHeader 0_libft/src/*/*.c | grep --color=always 'Error!\|Error:' || echo "$(G)Everything is OK!$(X)" >&1

debug: CFLAGS += -O0 -DDEBUG -g
debug: all

release: fclean
release: CFLAGS	+= -O2 -DNDEBUG
release: all
