/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_sprites_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:08:41 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/04 13:25:46 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"


static void	ft_down_frames(t_mlx *mlx, t_player *player)
{
	int			i;
	int			j;
	
	player->imgs->p_d_2 = mlx_xpm_file_to_image(mlx->mlx, "./images/player/animation/front/link_front_2.xpm", &i, &j);
	player->imgs->p_d_3 = mlx_xpm_file_to_image(mlx->mlx, "./images/player/animation/front/link_front_3.xpm", &i, &j);
}

static void	ft_right_frames(t_mlx *mlx, t_player *player)
{
	int			i;
	int			j;
	
	player->imgs->p_r_2 = mlx_xpm_file_to_image(mlx->mlx, "./images/player/animation/right/link_right_2.xpm", &i, &j);
	player->imgs->p_r_3 = mlx_xpm_file_to_image(mlx->mlx, "./images/player/animation/right/link_right_3.xpm", &i, &j);
}

static void	ft_left_frames(t_mlx *mlx, t_player *player)
{
	int			i;
	int			j;
	
	player->imgs->p_l_2 = mlx_xpm_file_to_image(mlx->mlx, "./images/player/animation/left/link_left_2.xpm", &i, &j);
	player->imgs->p_l_3 = mlx_xpm_file_to_image(mlx->mlx, "./images/player/animation/left/link_left_3.xpm", &i, &j);
}





void	ft_init_frames(t_vars *vars)
{
	t_player	*player;
	t_animation	*frames;
	
	player = vars->player;
	ft_down_frames(vars->mlx, player);
	ft_right_frames(vars->mlx, player);
	ft_left_frames(vars->mlx, player);
}