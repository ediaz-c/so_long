/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:58:33 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/03 18:04:47 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_free_matriz(char **matriz)
{
	int	i;

	i = 0;
	while (matriz[i] != 0)
	{
		free(matriz[i]);
		i++;
	}
	free(matriz);
}
