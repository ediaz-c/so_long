/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player_entity.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:17:58 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/01 20:11:23 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	ft_img_init(t_player *player, t_mlx *mlx)
{
	t_p_sprites	*img;
	int i;
	int j;

	player->imgs = malloc(sizeof(t_p_sprites));
	if (img == NULL)
		return ;
	img = player->imgs;
	img->img_front = mlx_xpm_file_to_image(mlx->mlx, "./images/player/link_front_stop.xpm", &i, &j);
	img->img_back = mlx_xpm_file_to_image(mlx->mlx, "./images/player/link_back_stop.xpm", &i, &j);
	img->img_right = mlx_xpm_file_to_image(mlx->mlx, "./images/player/link_right_stop.xpm", &i, &j);
	img->img_left = mlx_xpm_file_to_image(mlx->mlx, "./images/player/link_left_stop.xpm", &i, &j);
	player->img_current = player->imgs->img_front;
}

int	ft_init_player(t_vars *vars)
{
	t_player	*player;
	t_mlx		*mlx;

	player = vars->player;
	mlx = vars->mlx;
	ft_render_map(vars->map_game, mlx);
	ft_img_init(player, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, player->img_current, (player->x * 64) + 6 , player->y * 64);
	return (1);
}

void	ft_init_entity(t_vars *vars)
{
	int			i;
	int			j;
	int			n_ent;
	t_entity	*entity;
	t_mlx		*mlx;
	
	n_ent = 0;
	mlx = vars->mlx;
	entity = vars->entity;
	entity->img = mlx_xpm_file_to_image(mlx->mlx, "./images/entity/rupia.xpm", &i, &j);
	while (n_ent < vars->num_collected)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, entity->img, (entity[n_ent].x * 64) + 22, (entity[n_ent].y * 64) + 20);
		n_ent++;
	}
}

void	ft_init_door(t_vars *vars)
{
	t_exit	*door;
	t_mlx	*mlx;
	int	i;
	int j;
	
	door = vars->exit;
	mlx = vars->mlx;
	door->img_close = mlx_xpm_file_to_image(mlx->mlx, "./images/exit/door_close.xpm", &i, &j);
	door->img_open = mlx_xpm_file_to_image(mlx->mlx, "./images/exit/door_open.xpm", &i, &j);
	door->img_current = door->img_close;
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, door->img_current, (door->x * 64) + 9, door->y * 64);
}