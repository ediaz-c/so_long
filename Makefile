# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 15:32:01 by ediaz--c          #+#    #+#              #
#    Updated: 2023/11/19 13:47:36 by ediaz--c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
NAME_BONUS			=	so_long_bonus
RM				=	rm -rf
CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra
INCLUDE			=	-L./mlx/ -lmlx -framework AppKit -framework OpenGL
LIBFT_LIB		=	libft/libft.a
PRINTF_LIB		=	printf/libftprintf.a

GNL				=	get_next_line.c get_next_line_utils.c
SRC_GNL			=	$(addprefix gnl/, $(GNL))
OBJS_GNL		=	$(SRC_GNL:.c=.o)

GAME			=	ft_check_file.c ft_check_map.c ft_check_map_utils.c ft_check_wayout.c ft_error.c ft_free.c ft_game.c ft_gen_map.c ft_init_game.c ft_init_player_entity.c ft_init_utils.c ft_movements.c ft_print_map.c ft_render.c so_long.c
SRC_GAME		=	$(addprefix src/, $(GAME))
OBJS_GAME		=	$(SRC_GAME:.c=.o)

# BONUS
GAME_BONUS		=	ft_animation_bonus.c ft_check_file_bonus.c ft_check_map_bonus.c ft_check_map_utils_bonus.c ft_check_wayout_bonus.c ft_enemy_bonus.c ft_error_bonus.c ft_free_bonus.c ft_game_bonus.c ft_gen_map_bonus.c ft_init_game_bonus.c ft_init_player_entity_bonus.c ft_init_utils_bonus.c ft_movements_bonus.c ft_player_sprites_bonus.c ft_print_map_bonus.c ft_put_move_bonus.c ft_render_bonus.c so_long_bonus.c ft_sprites_door.c
SRC_GAME_BONUS	=	$(addprefix bonus/, $(GAME_BONUS))
OBJS_GAME_BONUS	=	$(SRC_GAME_BONUS:.c=.o)


Off		=	"\033[0m"
BBlack	=	"\033[1;30m"
BRed	=	"\033[1;31m"
BGreen	=	"\033[1;32m"
BYellow	=	"\033[1;33m"
BBlue	=	"\033[1;34m"
BPurple	=	"\033[1;35m"
BCyan	=	"\033[1;36m"
BWhite	=	"\033[1;37m"

Yellow	=	"\033[0;33m"

all:	$(NAME)

$(NAME):	$(OBJS_GAME) $(OBJS_GNL)
	@clear
	@printf $(BBlue)" Archivos compilados\n"$(Off)
	@echo $(BBlue) "Creando Libreria de LIBFT" $(Off)
	@make -C libft/
	@echo $(BBlue) "Creando Libreria de PRINTF" $(Off)
	@make -C printf/
	@make -C mlx/
	@$(CC) $(CFLAGS) $(INCLUDE) $(LIBFT_LIB) $(PRINTF_LIB) mlx/libmlx.a $(OBJS_GAME) $(OBJS_GNL) -o $(NAME)

bonus:	$(OBJS_GAME_BONUS) $(OBJS_GNL)
	@clear
	@printf $(BBlue)" Archivos del bonus compilados\n"$(Off)
	@echo $(BBlue) "Creando Libreria de LIBFT" $(Off)
	@make -C libft/
	@echo $(BBlue) "Creando Libreria de PRINTF" $(Off)
	@make -C printf/
	@$(CC) $(CFLAGS) $(INCLUDE) $(LIBFT_LIB) $(PRINTF_LIB) mlx/libmlx.a $(OBJS_GAME_BONUS) $(OBJS_GNL) -o $(NAME_BONUS)
	
norm:
	@printf $(BBlue)"Norma SRC:"$(Yellow)"\n"
	@norminette src
	@printf $(BBlue)"Norma LIBFT/:"$(Yellow)"\n"
	@norminette libft
	@printf $(BBlue)"Norma PRINTF/:"$(Yellow)"\n"
	@norminette printf
	@printf $(BBlue)"Norma GNL/:"$(Yellow)"\n"
	@norminette gnl
	@printf $(BBlue)"Norma INCLUDES/:"$(Yellow)"\n"
	@norminette includes
	@printf $(BBlue)"Norma bonus/:"$(Yellow)"\n"
	@norminette bonus
	
cleanBonus:
	@sleep 0.5
	@printf $(BBlue)"Eliminando objetos:\n"$(BRed)" ✅ Libft\n"
	@make clean -C libft
	@sleep 0.5
	@printf " ✅ Printf\n"
	@make clean -C printf
	@make clean -C mlx
	@sleep 0.5; printf " ✅ Get_next_line\n"
	@sleep 0.5; printf  " ✅ So_long_bonus\n\n"$(Off)
	@$(RM) $(OBJS_GAME_BONUS) $(OBJS_GNL)
	
fcleanBonus: cleanBonus
	@sleep 0.5; printf $(BBlue)"Eliminando:\n"$(BRed)
	@sleep 0.5; printf " ✅ libft.a\n"
	@make fclean -C libft
	@sleep 0.5; printf " ✅ libftprintf.a\n"
	@make fclean -C printf
	@sleep 0.5; printf " ✅ so_long_bonus\n"$(Off)
	@$(RM) $(NAME_BONUS)
clean:
	@sleep 0.5
	@printf $(BBlue)"Eliminando objetos:\n"$(BRed)" ✅ Libft\n"
	@make clean -C libft
	@sleep 0.5
	@printf " ✅ Printf\n"
	@make clean -C printf
	@make clean -C mlx
	@sleep 0.5; printf " ✅ Get_next_line\n"
	@sleep 0.5; printf  " ✅ So_long\n\n"$(Off)
	@$(RM) $(OBJS_GAME) $(OBJS_GNL)

fclean:	clean
	@sleep 0.5; printf $(BBlue)"Eliminando:\n"$(BRed)
	@sleep 0.5; printf " ✅ libft.a\n"
	@make fclean -C libft
	@sleep 0.5; printf " ✅ libftprintf.a\n"
	@make fclean -C printf
	@sleep 0.5; printf " ✅ so_long\n"$(Off)
	@$(RM) $(NAME)

re:	fclean all
reBonus:	fcleanBonus bonus

.PHONY: re clean fclean norm