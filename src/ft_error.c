/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:32:23 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/02 16:50:43 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(char *str)
{
	ft_printf("\033[1;31mERROR: \033[0;97m%s\n", str);
	exit(1);
}

void	ft_char_error(char c)
{
	ft_printf("\033[1;31mERROR: \033[0;97mcCarácter invalido '%c'\n", c);
	exit(1);
}
