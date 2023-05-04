/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:09:35 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/04 15:28:25 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_put_move(t_vars *vars)
{
	t_mlx	*mlx;
	char	*str;
	char	*move;
	char	*rupees;

	mlx = vars->mlx;
	move = ft_strdup("MOVES: ");
	str = ft_itoa(vars->player->move);
	move = ft_strjoin(move, str);
	free(str);
	mlx_string_put(mlx->mlx, mlx->mlx_win, vars->x * 30, (vars->y * 64) + 5, 191910199, move);
	rupees = ft_strdup("RUPEES: ");
	str = ft_itoa(vars->player->rupees);
	rupees = ft_strjoin(rupees, str);
	mlx_string_put(mlx->mlx, mlx->mlx_win, vars->x * 15, (vars->y * 64) + 5, 999999000, rupees);
	free(str);
	free(rupees);
	free(move);
}
