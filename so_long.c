#include "so_long.h"

int main(int ac, char *av[])
{
    t_vars  vars;

    if (ac != 2)
    {
        ft_error("Número de argumentos invalido");
    }
    if (ft_check_file(av[1]) == 0)
        ft_error("Ruta o archivo invalido");
    vars.map = ft_check_map(av[1]);
}