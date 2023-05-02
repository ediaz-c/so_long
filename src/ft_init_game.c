/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:48:23 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/02 18:03:39 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_game(t_vars *vars)
{
	ft_render_map(vars->map_game, vars->mlx);
	ft_init_player(vars);
	ft_init_entity(vars);
	ft_init_door(vars);
}