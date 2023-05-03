# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 15:32:01 by ediaz--c          #+#    #+#              #
#    Updated: 2023/05/03 17:54:49 by ediaz--c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
RM			=	rm -rf
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
INCLUDE		=	-lmlx -framework AppKit -framework OpenGL
LIBFT_LIB	=	libft/libft.a
PRINTF_LIB	=	printf/libftprintf.a

GNL			=	get_next_line.c get_next_line_utils.c
SRC_GNL		=	$(addprefix gnl/, $(GNL))
OBJS_GNL	=	$(SRC_GNL:.c=.o)

GAME		=	ft_check_file.c ft_check_map.c ft_check_map_utils.c ft_check_wayout.c ft_error.c ft_free.c ft_game.c ft_gen_map.c ft_init_game.c ft_init_player_entity.c ft_init_utils.c ft_movements.c ft_print_map.c ft_render.c so_long.c
SRC_GAME	=	$(addprefix src/, $(GAME))
OBJS_GAME	=	$(SRC_GAME:.c=.o)

# BONUS


Off		=	"\033[0m"
BBlack	=	"\033[1;30m"
BRed	=	"\033[1;31m"
BGreen	=	"\033[1;32m"
BYellow	=	"\033[1;33m"
BBlue	=	"\033[1;34m"
BPurple	=	"\033[1;35m"
BCyan	=	"\033[1;36m"
BWhite	=	"\033[1;37m"

all:	$(NAME)

$(NAME):	$(OBJS_GAME) $(OBJS_GNL) 
	@echo $(BBlue) "Creando Libreria de LIBFT" $(Off)
	@make -C libft/
	@echo $(BBlue) "Creando Libreria de PRINTF" $(Off)
	@make -C printf/
	@$(CC) $(CFLAGS) $(INCLUDE) $(LIBFT_LIB) $(PRINTF_LIB) $(OBJS_GAME) $(OBJS_GNL) -o $(NAME)

bonus:
	
clean:
	@sleep 0.5
	@printf $(BBlue)"Eliminando objetos:\n"$(BRed)" ✅ Libft\n"
	@make clean -C libft
	@sleep 0.5
	@printf " ✅ Printf\n"
	@make clean -C printf
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

re: fclean all

.PHONY: re clean fclean