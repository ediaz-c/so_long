/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_animation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:34:10 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/03 19:16:15 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_animation_up(t_vars	*vars, t_player *player, t_animation	*frames)
{
	int	i;
	t_mlx	*mlx;

	i = 0;
	mlx = vars->mlx;
	while (frames->up_frame[i] != NULL)
	{
		ft_render_map(vars->map_game, vars->mlx);
		// ft_printf("%d\n", i);
		// ft_render_entity(vars);
		// ft_printf("%d\n", i);
		// ft_render_door(vars);
		// ft_printf("%d\n", i);
		usleep(1000000);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, frames->up_frame[i], player->x * 64, player->y + (8 * (i + 1)));
		ft_printf("%d\n", i);
		i++;
	}
	
}