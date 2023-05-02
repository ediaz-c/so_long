/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 17:20:23 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/02 16:50:11 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_split(char **array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (array[i])
		i++;
	while (j < i)
		free(array[j++]);
	free(array);
}

int	ft_check_file(const char *str)
{
	char	**path;
	int		i;

	i = 0;
	path = ft_split(str, '/');
	if (path == NULL)
		return (0);
	while (path[i] && path[i + 1])
		i++;
	if (ft_strnstr(path[i], ".ber", ft_strlen(path[i])) == 0)
		return (0);
	ft_free_split(path);
	return (1);
}
