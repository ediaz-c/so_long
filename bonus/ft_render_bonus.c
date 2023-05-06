/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:30:42 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/06 15:09:39 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_render_entity(t_vars *vars)
{
	int			n_ent;
	t_entity	*entity;
	t_mlx		*mlx;

	n_ent = 0;
	mlx = vars->mlx;
	entity = vars->entity;
	while (n_ent < vars->num_collected)
	{
		if (entity[n_ent].collected == 0)
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, entity->img,
				(entity[n_ent].x * 64) + 22, (entity[n_ent].y * 64) + 20);
		n_ent++;
	}
}

void	ft_check_collected(t_player *player, t_entity *entity, int num_entity)
{
	int	i;

	i = 0;
	while (i < num_entity)
	{
		if ((player->x == entity[i].x) && (player->y == entity[i].y)
			&& entity[i].collected == 0)
		{
			entity[i].collected = 1;
			player->rupees++;
		}
		i++;
	}
}

void	ft_render_door(t_vars *vars)
{
	t_exit	*door;
	t_mlx	*mlx;

	mlx = vars->mlx;
	door = vars->exit;
	if (vars->num_collected == vars->player->rupees)
		ft_sprites_door(door);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, door->img_current, (door->x
			* 64) + 20, door->y * 64);
}

void	ft_check_end(t_vars *vars)
{
	t_player	*player;
	t_exit		*door;

	player = vars->player;
	door = vars->exit;
	if ((player->x == door->x) && (player->y == door->y))
		ft_close(KEY_ESC, vars->mlx);
}

int	ft_render(t_vars *vars)
{
	ft_render_map(vars->map_game, vars->mlx);
	ft_render_entity(vars);
	ft_render_player(vars);
	ft_render_door(vars);
	ft_render_enemy(vars);
	ft_check_dead(vars);
	ft_check_collected(vars->player, vars->entity, vars->num_collected);
	ft_put_move(vars);
	if (vars->player->rupees == vars->num_collected)
		ft_check_end(vars);
	return (1);
}
