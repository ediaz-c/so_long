#include "so_long.h"

int main(int ac, char *av[])
{
    t_vars  vars;
    char *path;
    int i;

    i = 0;
    path = av[1];
    if (ac != 2)
        ft_error("Número de argumentos invalido");
    if (ft_check_file(path) == 0)
        ft_error("Ruta o archivo invalido");
    vars.map = ft_gen_map(path);
    if (vars.map == NULL)
        return (0);
    ft_check_map(&vars);

    system("leaks a.out");
}