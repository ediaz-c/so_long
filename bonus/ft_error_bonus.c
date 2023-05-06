/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:32:23 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/06 15:34:10 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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

void	ft_win(void)
{
	ft_printf("\033[1;32mHAS GANADOg\033[0m\n");
	exit(1);
}

void	ft_dead(void)
{
	ft_printf("\033[1;31mHAS MUERTO\n");
	exit(1);
}
