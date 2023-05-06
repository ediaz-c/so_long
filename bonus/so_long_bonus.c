/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:03:48 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/06 14:23:18 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

// void seeleaks()
// {
// 	system("leaks -q so_long");
// }
// 	atexit(&seeleaks);

int	main(int ac, char *av[])
{
	t_vars	vars;
	char	*path;
	int		i;

	i = -1;
	path = av[1];
	if (ac != 2)
		ft_error("Número de argumentos invalido");
	if (ft_check_file(path) == 0)
		ft_error("Ruta o archivo invalido");
	vars.map = ft_gen_map(path);
	if (vars.map == NULL)
		return (0);
	if (ft_check_map(&vars))
	{
		ft_game(&vars);
	}
}
