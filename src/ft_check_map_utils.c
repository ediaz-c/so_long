/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:57:40 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/06 13:51:59 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_long_border(char *border)
{
	int	i;

	i = 0;
	while (border[i])
	{
		if (border[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_border(char *border)
{
	int	i;

	i = 0;
	while (border[i])
	{
		if (border[0] != '1' || (border[i + 1] == '\0' && border[i] != '1'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_char(char c)
{
	if (c == 'C')
		return (1);
	else if (c == 'E')
		return (1);
	else if (c == 'P')
		return (1);
	else if (c == '1')
		return (1);
	else if (c == '0')
		return (1);
	return (0);
}

t_map	ft_init_vars(void)
{
	t_map	map;

	map.c = 0;
	map.e = 0;
	map.p = 0;
	map.x = 0;
	map.y = 0;
	return (map);
}

char	**ft_cpy_map(char **map)
{
	char	**cpy;
	int		i;

	i = 0;
	while (map[i])
		i++;
	cpy = (char **)malloc (sizeof(char *) * (i + 1));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (map[i])
	{
		cpy[i] = ft_strdup(map[i]);
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}
