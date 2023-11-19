/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:14:22 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/11/19 13:44:37 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_up(t_vars *vars)
{
	t_player	*player;
	char		**map;

	player = vars->player;
	map = vars->map;
	player->img_current = player->imgs->img_back;
	if (map[player->y - 1][player->x] != '1')
	{
		player->last_move = KEY_UP;
		player->time = 0;
		player->y -= 1;
		return (1);
	}
	return (0);
}

int	ft_down(t_vars *vars)
{
	t_player	*player;
	char		**map;

	map = vars->map;
	player = vars->player;
	player->img_current = player->imgs->img_front;
	if (map[player->y + 1][player->x] != '1')
	{
		player->last_move = KEY_DOWN;
		player->time = 0;
		player->y += 1;
		return (1);
	}
	return (0);
}

int	ft_right(t_vars *vars)
{
	t_player	*player;
	char		**map;

	map = vars->map;
	player = vars->player;
	player->img_current = player->imgs->img_right;
	if (map[player->y][player->x + 1] != '1')
	{
		player->last_move = KEY_RIGHT;
		player->time = 0;
		player->x += 1;
		return (1);
	}
	return (0);
}

int	ft_left(t_vars *vars)
{
	t_player	*player;
	char		**map;

	map = vars->map;
	player = vars->player;
	player->img_current = player->imgs->img_left;
	if (map[player->y][player->x - 1] != '1')
	{
		player->last_move = KEY_LEFT;
		player->time = 0;
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
	ft_animation(player);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, player->img_current,
		player->x * 64 + 6, player->y * 64);
	return (1);
}
