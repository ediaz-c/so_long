/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:25:51 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/04/29 18:10:56 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_ESC 53

typedef struct s_vars
{
	int				x;
	int				y;
	char			**map;
	char			**map_game;
	int				num_collected;
	struct s_player	*player;
	struct s_entity	*entity;
	struct s_mlx	*mlx;
}			t_vars;

typedef struct s_map
{
	int		c;
	int		p;
	int		e;
	int		z;
	int		x;
	int		y;
}			t_map;

typedef struct s_player
{
	int			x;
	int			y;
	void		*img_player;
	int	move;
}			t_player;

typedef struct s_entity
{
	int		x;
	int		y;
	int		collected;
}			t_entity;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img_floor;
	void	*img_wall;
	char	*path;
	int		img_height;
	int		img_width;
}			t_mlx;

char		**ft_gen_map(char *path);
int			ft_check_file(const char *str);
void		ft_error(char *str);
void		ft_free_split(char **array);
int			ft_check_long_border(char *border);
int			ft_check_border(char *border);
void		ft_char_error(char c);
int			ft_check_map(t_vars *vars);
int			ft_check_char(char c);
t_map		ft_init_vars(void);
int			ft_check_wayout(t_vars *vars, t_player *player);
char		**ft_cpy_map(char **map);
void		ft_free_matriz(char **matriz);
void		ft_init_game(t_vars *vars);
t_entity	*ft_find_entity(char **map, int n_entity);
void		ft_print_map(char **map);
t_player	*ft_find_player(char **map);
void	ft_up(t_vars *vars, int *i, int *j);
void	ft_down(t_vars *vars, int *i, int *j);
void	ft_right(t_vars *vars, int *i, int *j);
void	ft_left(t_vars *vars, int *i, int *j);
#endif
