/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:25:51 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/06 14:18:28 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
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
	int					x;
	int					y;
	char				**map;
	char				**map_game;
	int					num_collected;
	struct s_player		*player;
	struct s_entity		*entity;
	struct s_mlx		*mlx;
	struct s_exit		*exit;
}						t_vars;

typedef struct s_map
{
	int					c;
	int					p;
	int					e;
	int					z;
	int					x;
	int					y;
}						t_map;

typedef struct s_player
{
	int					x;
	int					y;
	int					move;
	int					rupees;
	void				*img_current;
	struct s_p_sprites	*imgs;
}						t_player;

typedef struct s_entity
{
	int					x;
	int					y;
	void				*img;
	int					collected;
}						t_entity;

typedef struct s_mlx
{
	void				*mlx;
	void				*mlx_win;
	void				*img_floor;
	void				*img_wall;
	char				*path;
	int					img_height;
	int					img_width;
}						t_mlx;

typedef struct s_p_sprites
{
	void				*img_front;
	void				*img_back;
	void				*img_right;
	void				*img_left;
}						t_p_sprites;

typedef struct s_exit
{
	int					x;
	int					y;
	void				*img_close;
	void				*img_open;
	void				*img_current;
}						t_exit;

char					**ft_gen_map(char *path);
int						ft_check_file(const char *str);
void					ft_error(char *str);
void					ft_free_split(char **array);
int						ft_check_long_border(char *border);
int						ft_check_border(char *border);
void					ft_char_error(char c);
int						ft_check_map(t_vars *vars);
int						ft_check_char(char c);
t_map					ft_init_vars(void);
int						ft_check_wayout(t_vars *vars, t_player *player);
char					**ft_cpy_map(char **map);
void					ft_free_matriz(char **matriz);
void					ft_game(t_vars *vars);
t_entity				*ft_find_entity(char **map, int n_entity);
void					ft_print_map(char **map);
t_player				*ft_find_player(char **map);
int						ft_up(t_vars *vars);
int						ft_down(t_vars *vars);
int						ft_right(t_vars *vars);
int						ft_left(t_vars *vars);
void					ft_init_game(t_vars *vars);
void					ft_render_map(char **map, t_mlx *mlx);
int						ft_init_player(t_vars *vars);
int						ft_render_player(t_vars *vars);
void					ft_init_entity(t_vars *vars);
int						ft_render(t_vars *vars);
t_exit					*ft_find_exit(char **map);
void					ft_init_door(t_vars *vars);
int						ft_close(int key, t_mlx *mlx);
void					ft_win(void);
#endif
