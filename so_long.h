/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:25:51 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/04/23 11:35:04 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./printf/ft_printf.h"
#include "./gnl/get_next_line.h"

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_ESC 53

typedef struct s_vars
{
    int		x;
	int		y;
	char	**map;
	int		num_collected;
} t_vars;

typedef struct s_map
{
	int	c;
	int	p;
	int	e;
	int	z;
	int	x;
	int	y;
} t_map;

typedef struct s_player
{
	int x;
	int y;
} t_player;

typedef struct s_entity
{
	int	x;
	int	y;
	int	collected;
}	t_entity;

char	**ft_gen_map(char *path);
int		ft_check_file(const char *str);
void	ft_error(char *str);
void	ft_free_split(char **array);
int		ft_check_long_border(char *border);
int		ft_check_border(char *border);
void	ft_char_error(char c);
int    ft_check_map(t_vars *vars);
int 	ft_check_char(char c);
t_map 	ft_init_vars();
int ft_check_wayout(char **map, t_player player);
#endif
