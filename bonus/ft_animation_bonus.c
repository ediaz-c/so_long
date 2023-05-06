/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:35:35 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/06 15:12:33 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	ft_animation_down(t_player *player)
{
	if (player->last_move == KEY_DOWN)
	{
		if (player->time == 200)
			player->img_current = player->imgs->p_d_2;
		else if (player->time == 220)
			player->img_current = player->imgs->p_d_3;
		else if (player->time == 240)
			player->img_current = player->imgs->p_d_2;
		else if (player->time == 260)
		{
			player->img_current = player->imgs->img_front;
			player->time = 0;
		}
	}
}

static void	ft_animation_right(t_player *player)
{
	if (player->last_move == KEY_RIGHT)
	{	
		if (player->time == 200)
			player->img_current = player->imgs->p_r_2;
		else if (player->time == 220)
			player->img_current = player->imgs->p_r_3;
		else if (player->time == 240)
			player->img_current = player->imgs->p_r_2;
		else if (player->time == 260)
		{
			player->img_current = player->imgs->img_right;
			player->time = 0;
		}
	}
}

static void	ft_animation_left(t_player *player)
{
	if (player->last_move == KEY_LEFT)
	{
		if (player->time == 200)
			player->img_current = player->imgs->p_l_2;
		else if (player->time == 220)
			player->img_current = player->imgs->p_l_3;
		else if (player->time == 240)
			player->img_current = player->imgs->p_l_2;
		else if (player->time == 260)
		{
			player->img_current = player->imgs->img_left;
			player->time = 0;
		}
	}
}

void	ft_animation(t_player *player)
{
	player->time++;
	if (player->last_move == KEY_DOWN)
		ft_animation_down(player);
	else if (player->last_move == KEY_RIGHT)
		ft_animation_right(player);
	else if (player->last_move == KEY_LEFT)
		ft_animation_left(player);
	else
		return ;
}
