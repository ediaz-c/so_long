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
    int		win_width;
	int		win_height;
	char	**map;
} t_vars;

typedef struct s_map
{
	int	c;
	int	p;
	int	e;
	int	x;
	int	y;
} t_map;


char	**ft_gen_map(char *path);
int		ft_check_file(const char *str);
void	ft_error(char *str);
void	ft_free_split(char **array);
#endif
