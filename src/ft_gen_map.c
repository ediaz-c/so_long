/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:35:12 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/02 18:03:36 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Abrir el archivo y generar una matriz*/

static char	*ft_read_file(char *path)
{
	int		fd;
	char	*line;
	char	*all_lines;

	all_lines = ft_strdup("");
	line = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error("Error al abrir el archivo");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		all_lines = ft_strjoin(all_lines, line);
		free(line);
		line = NULL;
	}
	return (all_lines);
}

static int	ft_check_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) == ft_strlen(map[i + 1]))
			i++;
		else if (map[i + 1] == NULL)
			i++;
		else
			break ;
	}
	if (i < 3 || map[i] != NULL)
		return (0);
	return (1);
}

char	**ft_gen_map(char *path)
{
	char	*all_lines;
	char	**matriz;

	all_lines = ft_read_file(path);
	if (all_lines == NULL)
		return (NULL);
	matriz = ft_split(all_lines, '\n');
	free(all_lines);
	if (matriz == NULL)
		return (NULL);
	if (ft_check_lines(matriz) == 0)
	{
		free(matriz);
		ft_error("Tamaño del mapa invalido");
		return (NULL);
	}
	return (matriz);
}
