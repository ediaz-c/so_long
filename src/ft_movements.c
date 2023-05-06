/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:14:22 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/03 17:46:41 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_up(t_vars *vars)
{
	t_player	*player;
	t_mlx		*mlx;
	char		**map;

	player = vars->player;
	mlx = vars->mlx;
	map = vars->map;
	player->img_current = player->imgs->img_back;
	if (map[player->y - 1][player->x] != '1')
	{
		player->y -= 1;
		return (1);
	}
	return (0);
}

int	ft_down(t_vars *vars)
{
	t_player	*player;
	t_mlx		*mlx;
	char		**map;

	map = vars->map;
	player = vars->player;
	mlx = vars->mlx;
	player->img_current = player->imgs->img_front;
	if (map[player->y + 1][player->x] != '1')
	{
		player->y += 1;
		return (1);
	}
	return (0);
}

int	ft_right(t_vars *vars)
{
	t_player	*player;
	t_mlx		*mlx;
	char		**map;

	map = vars->map;
	player = vars->player;
	mlx = vars->mlx;
	player->img_current = player->imgs->img_right;
	if (map[player->y][player->x + 1] != '1')
	{
		player->x += 1;
		return (1);
	}
	return (0);
}

int	ft_left(t_vars *vars)
{
	t_player	*player;
	t_mlx		*mlx;
	char		**map;

	map = vars->map;
	player = vars->player;
	mlx = vars->mlx;
	player->img_current = player->imgs->img_left;
	if (map[player->y][player->x - 1] != '1')
	{
		player->x -= 1;
		return (1);
	}
	return (0);
}

int	ft_render_player(t_vars *vars)
{
	t_player	*player;
	t_mlx		*mlx;

	player = vars->player;
	mlx = vars->mlx;
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, player->img_current,
		(player->x * 64) + 6, player->y * 64);
	return (1);
}
