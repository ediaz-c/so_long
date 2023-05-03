/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wayout_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:15:45 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/03 18:04:43 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
				return (0);
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

int	ft_check_wayout(t_vars *vars, t_player *player)
{
	char	**map_cpy;

	map_cpy = ft_cpy_map(vars->map);
	ft_find_wayout(map_cpy, player->x, player->y);
	if (ft_is_wayout(map_cpy))
	{
		free(player);
		vars->map_game = map_cpy;
		return (1);
	}
	return (0);
}
