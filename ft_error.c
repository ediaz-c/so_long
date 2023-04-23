#include "so_long.h"

void	ft_error(char *str)
{
	ft_printf("\033[1;31mERROR: \033[0;97m%s\n", str);
	exit (1);
}