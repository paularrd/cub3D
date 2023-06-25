# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 10:47:02 by fle-tolg          #+#    #+#              #
#    Updated: 2023/05/04 09:31:25 by fle-tolg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#PROJECT
NAME	=	cub3D
NAME_B	=	cub3D_bonus

#COMMAND
CC		=	@clang
CFLAGS	=	-g -Wall -Wextra -Werror
IFLAGS	=	-Iinc -I/usr/include -I$(LIBMLX)/include
MLXFLAG	=	$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
MK		=	@mkdir -p
RM		=	@rm -f
HARDRM	=	@rm -rf
CLEAR	=	@clear
FILE	=	$(shell ls -l src/**/* | grep -F .c | wc -l)
CMP		=	1

# COLOR #
GREEN	=	\033[38;5;76m
RED		=	\033[38;5;124m
YELLOW	=	\033[38;5;226m
ORANGE	=	\033[38;5;202m
PURPLE	=	\033[38;5;213m
LBLUE	=	\033[38;5;51m
BLUE	=	\033[38;5;117m
INDI	=	\033[38;5;99m
RESET	=	\033[00m

P1	=	@printf "\r${RED}   ____ ${GREEN}  __    __ ${YELLOW}  ______ ${ORANGE}  _____ ${PURPLE}   ______    "
P2	=	printf "\n${RED}  / ___) ${GREEN} ) )  ( (  ${YELLOW}(_   _ \ ${ORANGE} )__  \ ${PURPLE} (_  __ \   "
P3	=	printf "\n${RED} / /     ${GREEN}( (    ) ) ${YELLOW}  ) (_) )${ORANGE}  __) / ${PURPLE}   ) ) \ \  "
P4	=	printf "\n${RED}( (      ${GREEN} ) )  ( (  ${YELLOW}  \   _/ ${ORANGE} (__ (  ${PURPLE}  ( (   ) ) "
P5	=	printf "\n${RED}( (      ${GREEN}( (    ) ) ${YELLOW}  /  _ \ ${ORANGE}    \ \ ${PURPLE}   ) )  ) ) "
P6	=	printf "\n${RED} \ \___  ${GREEN} ) \__/ (  ${YELLOW} _) (_) )${ORANGE} ___/  )${PURPLE}  / /__/ /  "
P7	=	printf "\n${RED}  \____) ${GREEN} \______/  ${YELLOW}(______/ ${ORANGE} )____/ ${PURPLE} (______/   ${RESET}\n\n"

HELL	=	$(P1);$(P2);$(P3);$(P4);$(P5);$(P6);$(P7);

#LIBFT
LIBFT_NAME	=	./libs/libft/libft.a
LIBFT_DIR	=	./libs/libft/ --no-print-directory

#MLX
LIBMLX			=	./libs/minilibx-linux
MLX_NAME		=	./libs/minilibx-linux/build/libmlx42.a
MLX_DIR			= 	./libs/minilibx-linux/ --no-print-directory

#SOURCES_MANDATORY
SRC_PARSING		:=	mandatory/parsing/parsing.c\
					mandatory/parsing/map_test_utils.c\
					mandatory/parsing/map_test.c\
					mandatory/parsing/read_map.c\
					mandatory/parsing/identifier.c\
					mandatory/parsing/texture.c\
					mandatory/parsing/test_wall.c\
					mandatory/parsing/add_spaces.c\
					mandatory/parsing/add_spaces_utils.c

SRC_UTILS		:=	mandatory/cub3d.c\
					mandatory/utils/utils_launch.c\
					mandatory/utils/close_program.c\
					mandatory/utils/utils_orientation.c

SRC_EVENT		:=	mandatory/events/key_press.c\
					mandatory/events/key_press_utils.c

SRC_RAYCASTING	:=	mandatory/raycasting/render.c\
					mandatory/raycasting/calc_dist.c\
					mandatory/raycasting/texture_ray.c

#SOURCES_BONUS
SRCB_PARSING	:=	bonus/parsing/parsing.c\
					bonus/parsing/map_test_utils.c\
					bonus/parsing/map_test.c\
					bonus/parsing/read_map.c\
					bonus/parsing/identifier.c\
					bonus/parsing/texture.c\
					bonus/parsing/test_wall.c\
					bonus/parsing/add_spaces.c\
					bonus/parsing/add_spaces_utils.c

SRCB_DOOR		:=	bonus/door/door.c

SRCB_MOUSE		:=	bonus/mouse/mouse_mouve.c

SRCB_ANIMATION	:=	bonus/animation/open_animation.c

SRCB_MINIMAP	:=	bonus/minimap/minimap.c\
					bonus/minimap/utils_minimap.c

SRCB_UTILS		:=	bonus/cub3d.c\
					bonus/utils/utils_launch.c\
					bonus/utils/close_program.c\
					bonus/utils/utils_orientation.c

SRCB_RAYCASTING	:=	bonus/raycasting/render.c\
					bonus/raycasting/calc_dist.c\
					bonus/raycasting/key_press.c\
					bonus/raycasting/key_arrow.c\
					bonus/raycasting/texture_ray.c

SRCS			=	$(SRC_UTILS) $(SRC_PARSING) $(SRC_EVENT) $(SRC_RAYCASTING)
SRCS_BONUS		=	$(SRCB_UTILS) $(SRCB_PARSING) $(SRCB_RAYCASTING) $(SRCB_MINIMAP) $(SRCB_DOOR) $(SRCB_MOUSE) $(SRCB_ANIMATION)

SRCS_MLX		=	$(shell find ./src -iname "*.c")

#OBJECTS
OBJS		=	$(addprefix objs/, $(SRCS:%.c=%.o))
OBJS_BONUS	=	$(addprefix objs/, $(SRCS_BONUS:%.c=%.o))
OBJS_DIR	=	objs
OBJS_DIR_B	=	objs_bonus
OBJS_MLX	=	${SRCS:.c=.o}

all : $(MLX_NAME) $(LIBFT_NAME) $(NAME)

bonus : $(MLX_NAME) $(LIBFT_NAME) $(NAME_B)

$(OBJS_DIR)/%.o: src/%.c
	$(MK) $(@D)
	@printf "\r$(LBLUE)[$(RESET)+$(LBLUE)] $(RESET)Compiling $(GREEN)$<$(BLUE) [$(RESET)$(CMP)$(BLUE)/$(RESET)$(FILE)$(BLUE)]$(RESET)         \r"
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@$(eval CMP=$(shell echo $$(($(CMP)+1))))

$(OBJS_DIR_B)/%.o: src/%.c
	$(MK) $(@D)
	@printf "\r$(LBLUE)[$(RESET)+$(LBLUE)] $(RESET)Compiling $(GREEN)$<$(BLUE) [$(RESET)$(CMP)$(BLUE)/$(RESET)$(FILE)$(BLUE)]$(RESET)         \r"
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@$(eval CMP=$(shell echo $$(($(CMP)+1))))

$(LIBFT_NAME):
	@make -C $(LIBFT_DIR)

$(MLX_NAME):
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(MLXFLAG) $(OBJS) $(LIBFT_NAME) $(MLX_NAME) -o $(NAME)
	@printf "\r                                                                          "
	$(HELL)

$(NAME_B) : $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(IFLAGS) $(MLXFLAG) $(OBJS_BONUS) $(LIBFT_NAME) $(MLX_NAME) -o $(NAME_B)
	@printf "\r                                                                          "
	$(HELL)

clean :
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJS_MLX)
	@rm -rf $(LIBMLX)/build
	$(HARDRM) $(OBJS_DIR)

fclean : clean
	@make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME) $(NAME_B)

re : fclean all

.PHONY :
	all clean fclean re
