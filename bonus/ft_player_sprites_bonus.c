/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_sprites_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:08:41 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/03 19:14:47 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	**ft_up_frames(t_mlx *mlx)
{
	void	**frames;
	int			i;
	int			j;
	void	*frame1;
	void	*frame2;
	void	*frame3;
	void	*frame4;
	void	*frame5;
	void	*frame6;
	void	*frame7;
	void	*frame8;
	void	*frame9;
	void	*frame10;
	
	frames = (void **)malloc(sizeof(void *) * (11));
	if (frames == NULL)
		ft_error("Malloc no alocado. 'ft_up_frames'");
	frame1 = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/back/link_back_1.xpm", &i, &j);
	frame2 = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/back/link_back_2.xpm", &i, &j);
	frame3 = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/back/link_back_3.xpm", &i, &j);
	frame4 = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/back/link_back_4.xpm", &i, &j);
	frame5 = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/back/link_back_5.xpm", &i, &j);
	frame6 = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/back/link_back_6.xpm", &i, &j);
	frame7 = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/back/link_back_7.xpm", &i, &j);
	frame8 = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/back/link_back_8.xpm", &i, &j);
	frame9 = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/back/link_back_9.xpm", &i, &j);
	frame10 = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/back/link_back_10.xpm", &i, &j);
	
	frames[0] = frame1;
	frames[1] = frame2;
	frames[2] = frame3;
	frames[3] = frame4;
	frames[4] = frame5;
	frames[5] = frame6;
	frames[6] = frame7;
	frames[7] = frame8;
	frames[8] = frame9;
	frames[9] = frame10;
	frames[10] = NULL;
	return (frames);
}
static void	**ft_down_frames(t_mlx *mlx)
{
	void	**frames;
	int			i;
	int			j;
	
	frames = malloc(sizeof(void *) * (11));
	if (frames == NULL)
		ft_error("Malloc no alocado. 'ft_down_frames'");
	frames[0] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/front/link_front_1.xpm", &i, &j);
	frames[1] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/front/link_front_2.xpm", &i, &j);
	frames[2] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/front/link_front_3.xpm", &i, &j);
	frames[3] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/front/link_front_4.xpm", &i, &j);
	frames[4] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/front/link_front_5.xpm", &i, &j);
	frames[5] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/front/link_front_6.xpm", &i, &j);
	frames[6] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/front/link_front_7.xpm", &i, &j);
	frames[7] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/front/link_front_8.xpm", &i, &j);
	frames[8] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/front/link_front_9.xpm", &i, &j);
	frames[9] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/front/link_front_10.xpm", &i, &j);
	frames[10] = NULL;
	return (frames);
}
static void	**ft_right_frames(t_mlx *mlx)
{
	void	**frames;
	int			i;
	int			j;
	
	frames = malloc(sizeof(void *) * (11));
	if (frames == NULL)
		ft_error("Malloc no alocado. 'ft_right_frames'");
	frames[0] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/right/link_right_1.xpm", &i, &j);
	frames[1] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/right/link_right_2.xpm", &i, &j);
	frames[2] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/right/link_right_3.xpm", &i, &j);
	frames[3] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/right/link_right_4.xpm", &i, &j);
	frames[4] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/right/link_right_5.xpm", &i, &j);
	frames[5] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/right/link_right_6.xpm", &i, &j);
	frames[6] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/right/link_right_7.xpm", &i, &j);
	frames[7] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/right/link_right_8.xpm", &i, &j);
	frames[8] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/right/link_right_9.xpm", &i, &j);
	frames[9] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/right/link_right_10.xpm", &i, &j);
	frames[10] = NULL;
	return (frames);
}
static void	**ft_left_frames(t_mlx *mlx)
{
	void	**frames;
	int			i;
	int			j;
	
	frames = malloc(sizeof(void *) * (11));
	if (frames == NULL)
		ft_error("Malloc no alocado. 'ft_left_frames'");
	frames[0] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/left/link_left_1.xpm", &i, &j);
	frames[1] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/left/link_left_2.xpm", &i, &j);
	frames[2] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/left/link_left_3.xpm", &i, &j);
	frames[3] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/left/link_left_4.xpm", &i, &j);
	frames[4] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/left/link_left_5.xpm", &i, &j);
	frames[5] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/left/link_left_6.xpm", &i, &j);
	frames[6] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/left/link_left_7.xpm", &i, &j);
	frames[7] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/left/link_left_8.xpm", &i, &j);
	frames[8] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/left/link_left_9.xpm", &i, &j);
	frames[9] = mlx_xpm_file_to_image(mlx->mlx, "../images/player/animation/left/link_left_10.xpm", &i, &j);
	frames[10] = NULL;
	return (frames);
}

void	ft_init_frames(t_vars *vars)
{
	t_player	*player;
	t_animation	*frames;

	player = vars->player;
	frames = player->frames;
	frames = malloc(sizeof(t_animation));
	if (frames == NULL)
		ft_error("Malloc no alocado");
	frames->up_frame = ft_up_frames(vars->mlx);
	frames->down_frame = ft_down_frames(vars->mlx);
	frames->right_frame = ft_right_frames(vars->mlx);
	frames->left_frame = ft_left_frames(vars->mlx);
}