/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites_door.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:46:52 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/06 15:30:35 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_sprites_door(t_exit *door)
{
	int	delay;

	door->time++;
	delay = door->time;
	if (delay >= 20 && delay <= 80)
	{
		if (delay == 20)
			door->img_current = door->img_1;
		else if (delay == 40)
			door->img_current = door->img_2;
		else if (delay == 60)
			door->img_current = door->img_3;
		else if (delay == 80)
		{
			door->img_current = door->img_4;
			door->time = 0;
		}
	}
	else if (delay < 0 || delay > 80)
		door->time = 0;
	return (door->time);
}
