/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:03:34 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/02 18:03:22 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_check_border_map(t_vars vars)
{
	int	i;

	i = 0;
	while (vars.map[i])
	{
		if (i == 0 && ft_check_long_border(vars.map[i]) == 0)
			break ;
		else if (vars.map[i + 1] == NULL
			&& ft_check_long_border(vars.map[i]) == 0)
			break ;
		else if (ft_check_border(vars.map[i]) == 0)
			break ;
		i++;
	}
	if (vars.map[i] != NULL)
		return (0);
	return (1);
}

static void	ft_check_characters(char **map)
{
	char	*char_permit;
	int		i;
	int		j;

	i = 0;
	char_permit = "10PCEZ";
	while (map[i])
	{
		j = 0;
		while (map[i][j] && ft_check_char(map[i][j]))
			j++;
		if (map[i][j] != '\0')
			ft_char_error(map[i][j]);
		i++;
	}
}

static t_map	ft_get_elements(char **map)
{
	int		j;
	int		i;
	t_map	vars_map;

	i = -1;
	vars_map = ft_init_vars();
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				vars_map.c ++;
			else if (map[i][j] == 'P')
				vars_map.p ++;
			else if (map[i][j] == 'E')
				vars_map.e ++;
			else if (map[i][j] == 'Z')
				vars_map.z ++;
		}
	}
	vars_map.x = j;
	vars_map.y = i;
	return (vars_map);
}

static void	ft_check_elements(t_map map)
{
	if (map.p != 1)
		ft_error("Error con el caracter 'P'");
	else if (map.e != 1)
		ft_error("Error con el caracter 'E'");
	else if (map.c < 1)
		ft_error("Error con el caracter 'C'");
}

int	ft_check_map(t_vars *vars)
{
	t_map		map_vars;
	t_player	*player;

	ft_check_characters(vars->map);
	map_vars = ft_get_elements(vars->map);
	player = ft_find_player(vars->map);
	ft_check_elements(map_vars);
	if (ft_check_border_map(*vars) == 0)
		ft_error("Error en los bordes del mapa");
	if (ft_check_wayout(vars, player) == 0)
		ft_error("Mapa no jugable");
	vars->x = map_vars.x;
	vars->y = map_vars.y;
	vars->num_collected = map_vars.c;
	return (1);
}
