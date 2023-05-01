/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:29:32 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/01 20:11:41 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_entity	*ft_find_entity(char **map, int n_entity)
{
	int			i;
	int			j;
	int			num_collect;
	t_entity	*entity;

	i = -1;
	num_collect = 0;
	entity = malloc(sizeof(t_entity) * (n_entity + 1));
	if (entity == NULL)
		return (NULL);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			if (map[i][j] == 'C')
			{
				entity[num_collect].x = j;
				entity[num_collect].y = i;
				entity[num_collect].collected = 0;
				num_collect++;
			}
		}
	}
	return (entity);
}

t_player	*ft_find_player(char **map)
{
	int			x;
	int			y;
	t_player	*player;

	y = -1;
	player = malloc(sizeof(t_player));
	if (player == NULL)
		return (NULL);
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'P')
			{
				player->x = x;
				player->y = y;
			}
		}
	}
	player->rupees = 0;
	player->move = 0;
	return (player);
}

t_exit	*ft_find_exit(char	**map)
{
	int		x;
	int		y;
	t_exit	*door;
	
	door = malloc(sizeof(t_exit));
	if (door == NULL)
		return (NULL);
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'E')
			{
				door->x = x;
				door->y = y;
			}
		}
	}

	return (door);
}
