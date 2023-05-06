/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:58:40 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/06 14:26:10 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_wall, x
					* 64, y * 64);
			else if (map[y][x] == ' ')
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_floor,
					x * 64, y * 64);
			x++;
		}
		y++;
	}
}

int	ft_close(int key, t_mlx *mlx)
{
	if (key && mlx)
		exit(1);
	exit(1);
	return (1);
}

static int	ft_player_hook(int key, t_vars *vars)
{
	int	j;
	int	i;
	int	ismove;

	ismove = 0;
	i = 0;
	j = 0;
	if (key == KEY_UP || key == KEY_W)
		ismove = ft_up(vars);
	else if (key == KEY_LEFT || key == KEY_A)
		ismove = ft_left(vars);
	else if (key == KEY_DOWN || key == KEY_S)
		ismove = ft_down(vars);
	else if (key == KEY_RIGHT || key == KEY_D)
		ismove = ft_right(vars);
	else if (key == KEY_ESC)
		ft_close(key, vars->mlx);
	if (ismove)
	{
		vars->player->move++;
		ft_printf("MOVES: %d\n", vars->player->move);
	}
	return (1);
}

static t_mlx	*ft_init_mlx(t_vars *vars)
{
	t_mlx	*mlx;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mlx = malloc(sizeof(t_mlx));
	if (mlx == NULL)
		return (NULL);
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		ft_error("Mlx no iniciada");
	mlx->img_floor = mlx_xpm_file_to_image(mlx->mlx, "./images/floor_game.xpm",
			&i, &j);
	mlx->img_wall = mlx_xpm_file_to_image(mlx->mlx, "./images/wall_game.xpm",
			&i, &j);
	mlx->mlx_win = mlx_new_window(mlx->mlx,
			(vars->x * 64), ((vars->y * 64) + 30),
			"So_long");
	if (!mlx->mlx_win || !mlx->img_floor || !mlx->img_wall)
		ft_error("Variables de la mlx no iniciadas");
	return (mlx);
}

void	ft_game(t_vars *vars)
{
	vars->entity = ft_find_entity(vars->map, vars->num_collected);
	vars->player = ft_find_player(vars->map);
	vars->enemy = ft_find_enemy(vars->map, vars->num_enemy);
	vars->mlx = ft_init_mlx(vars);
	ft_sprites_enemy(vars->mlx, vars->enemy, vars->num_enemy);
	vars->exit = ft_find_exit(vars->map);
	if (!vars->entity || !vars->player || !vars->mlx || !vars->enemy)
		ft_error("Error");
	ft_init_game(vars);
	vars->player->time = 0;
	mlx_hook(vars->mlx->mlx_win, 2, (1L << 0), ft_player_hook, vars);
	mlx_loop_hook(vars->mlx->mlx, ft_render, vars);
	mlx_hook(vars->mlx->mlx_win, 17, (1L << 17), ft_close, vars->mlx);
	mlx_loop(vars->mlx->mlx);
	ft_free_matriz(vars->map);
	ft_free_matriz(vars->map_game);
	free(vars->mlx);
	free(vars->player);
	free(vars->entity);
}
