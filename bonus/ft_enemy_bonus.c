/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:10:26 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/06 15:33:13 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_sprites_enemy(t_mlx *mlx, t_enemy *enemy, int num_enemy)
{
	int	i;
	int	a;
	int	b;

	i = 0;
	while (i < num_enemy)
	{
		enemy[i].img = mlx_xpm_file_to_image(mlx->mlx,
				"./images/enemy/foguito.xpm", &a, &b);
		if (enemy[i].img == NULL)
			ft_error("Sprite de enemigo no cargado");
		i++;
	}
}

t_enemy	*ft_find_enemy(char **map, int num_enemy)
{
	t_enemy	*enemy;
	int		i;
	int		j;
	int		x;

	enemy = malloc(sizeof(t_enemy) * (num_enemy));
	if (enemy == NULL)
		ft_error("Malloc");
	i = -1;
	x = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			if (map[i][j] == 'Z')
			{
				enemy[x].x = j;
				enemy[x].y = i;
				x++;
			}
		}
	}
	return (enemy);
}

void	ft_render_enemy(t_vars *vars)
{
	int			i;
	t_enemy		*enemy;
	t_mlx		*mlx;

	i = 0;
	enemy = vars->enemy;
	mlx = vars->mlx;
	while (i < vars->num_enemy)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			enemy[i].img, (enemy[i].x * 64) + 6, enemy[i].y * 64);
		i++;
	}
}

void	ft_check_dead(t_vars *vars)
{
	t_player	*player;
	t_enemy		*enemy;
	int			i;

	i = 0;
	player = vars->player;
	enemy = vars->enemy;
	while (i < vars->num_enemy)
	{
		if (player->x == enemy[i].x && player->y == enemy[i].y)
			ft_dead();
		i++;
	}
}
