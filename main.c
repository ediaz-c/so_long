#include "so_long.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		printf("Arriba\n");
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		printf("Izquierda\n");
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		printf("Abajo\n");
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		printf("Derecha\n");
	else if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
	}
	return (0);
}
int	mouse_hook(int mousecode, t_vars *vars)
{
	if (mousecode == 1)
		printf("Click Izquierdo\n");
	if (mousecode == 2)
		printf("Click Derecho\n");
	if (mousecode == 3)
		printf("Click del Raton\n");
	if (mousecode == 4)
		printf("Scroll Arriba\n");
	if (mousecode == 5)
		printf("Scroll Abajo\n");

		return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}
