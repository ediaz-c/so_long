/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wayout.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:15:45 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/04/26 13:15:47 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_is_wayout(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static char	**ft_find_wayout(char **map, int px, int py)
{
	map[py][px] = ' ';
	if (map[py - 1][px] != '1' && map[py - 1][px] != ' ')
		map = ft_find_wayout(map, px, py - 1);
	if (map[py][px + 1] != '1' && map[py][px + 1] != ' ')
		map = ft_find_wayout(map, px + 1, py);
	if (map[py][px - 1] != '1' && map[py][px - 1] != ' ')
		map = ft_find_wayout(map, px - 1, py);

	if (map[py + 1][px] != '1' && map[py + 1][px] != ' ')
		map = ft_find_wayout(map, px, py + 1);
	return (map);
}

int ft_check_wayout(char **map, t_player player)
{
	char	**map_cpy;
	// Crear copia dell mapa
    
	map_cpy = map;
	ft_find_wayout(map_cpy, player.x, player.y);
	return (ft_is_wayout(map_cpy));
}
