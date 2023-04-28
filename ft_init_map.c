/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:58:40 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/04/28 12:53:53 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
static void	ft_init_map(char **map, t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_wall, x * 64, y * 64);
			else if (map[y][x] == ' ')
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_floor, x * 64, y * 64);
			x++;
		}
		y++;
	}	
}

static	t_mlx	*ft_init_mlx(t_vars *vars)
{
	t_mlx	*mlx;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mlx = malloc (sizeof(t_mlx));
	if (mlx == NULL)
		return (NULL);
	mlx->mlx = mlx_init();
	mlx->img_floor = mlx_xpm_file_to_image(mlx->mlx, "./images/floor_game.xpm", &i, &j);
	mlx->img_wall = mlx_xpm_file_to_image(mlx->mlx, "./images/wall_game.xpm", &i, &j);
	mlx->mlx_win = mlx_new_window(mlx->mlx, (vars->x * 64), (vars->y * 64), "So_long");

	return (mlx);
}



void	ft_init_game(t_vars *vars)
{
	t_player	*player;
	t_entity	*entity;
	t_mlx		*mlx;
	
	entity = ft_find_entity(vars->map, vars->num_collected);
	player = ft_find_player(vars->map);
	mlx = ft_init_mlx(vars);
	if (entity == NULL || player == NULL || mlx == NULL)
		ft_error("Error");

	ft_init_map(vars->map_game, mlx);




	
	mlx_loop(mlx->mlx);
	ft_free_matriz(vars->map);
	ft_free_matriz(vars->map_game);
	free(mlx);
	free(player);
	free(entity);
}
