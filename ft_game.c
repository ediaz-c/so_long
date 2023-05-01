/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:58:40 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/01 20:34:14 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	ft_render_map(char **map, t_mlx *mlx)
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

int ft_close(int key, t_mlx *mlx)
{
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	// system("leaks a.out");
	exit(1);
	return (1);
}

static int	ft_player_hook(int key, t_vars *vars)
{
	int	j;
	int i;
	int	ismove;

	ismove = 0;
	i = 0;
	j = 0;
	if (key == KEY_UP || key == KEY_W)
		ismove = ft_up(vars, &i, &j);
	else if (key == KEY_LEFT || key == KEY_A)
		ismove = ft_left(vars, &i, &j);
	else if (key == KEY_DOWN || key == KEY_S)
		ismove = ft_down(vars, &i, &j);
	else if (key == KEY_RIGHT || key == KEY_D)
		ismove = ft_right(vars, &i, &j);
	else if (key == KEY_ESC)
		ft_close(key, vars->mlx);
	if (ismove)
	{
		vars->player->move++;
		ft_printf("MOVES: %d\n", vars->player->move);
	}
	return (1);
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


void	ft_game(t_vars *vars)
{
	vars->entity = ft_find_entity(vars->map, vars->num_collected);
	vars->player = ft_find_player(vars->map);
	vars->mlx = ft_init_mlx(vars);
	vars->exit = ft_find_exit(vars->map);
	if (vars->entity == NULL || vars->player == NULL || vars->mlx == NULL)
		ft_error("Error");
	ft_init_game(vars);


	mlx_key_hook(vars->mlx->mlx_win, ft_player_hook, vars);
	mlx_loop_hook(vars->mlx->mlx, ft_render, vars);
	mlx_hook(vars->mlx->mlx_win, 17, (1L << 17), ft_close, vars->mlx);
	
	mlx_loop(vars->mlx->mlx);
	ft_free_matriz(vars->map);
	ft_free_matriz(vars->map_game);
	free(vars->mlx);
	free(vars->player);
	free(vars->entity);
}
