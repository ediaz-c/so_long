/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:14:22 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/04/29 18:17:13 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_up(t_vars *vars, int *i, int *j)
{
	t_player	*player;
	t_mlx		*mlx;
	char	**map;

	player = vars->player;
	mlx = vars->mlx;
	map = vars->map;
	player->img_player = mlx_xpm_file_to_image(mlx->mlx, "./images/player/link_back_stop.xpm", i, j);
	if (map[player->y - 1][player->x] != '1')
		player->y -= 1;
}
void	ft_down(t_vars *vars, int *i, int *j)
{
	t_player	*player;
	t_mlx		*mlx;
	char		**map;

	map = vars->map;
	player = vars->player;
	mlx = vars->mlx;
	player->img_player = mlx_xpm_file_to_image(mlx->mlx, "./images/player/link_front_stop.xpm", i, j);
	if (map[player->y + 1][player->x] != '1')
		player->y += 1;
}
void	ft_right(t_vars *vars, int *i, int *j)
{
	t_player	*player;
	t_mlx		*mlx;
	char		**map;

	map = vars->map;
	player = vars->player;
	mlx = vars->mlx;
	player->img_player = mlx_xpm_file_to_image(mlx->mlx, "./images/player/link_right_stop.xpm", i, j);
	if (map[player->y][player->x + 1] != '1')
		player->x += 1;
}
void	ft_left(t_vars *vars, int *i, int *j)
{
	t_player	*player;
	t_mlx		*mlx;
	char		**map;

	map = vars->map;
	player = vars->player;
	mlx = vars->mlx;
	player->img_player = mlx_xpm_file_to_image(mlx->mlx, "./images/player/link_left_stop.xpm", i, j);
	if (map[player->y][player->x - 1] != '1')
		player->x -= 1;
}
