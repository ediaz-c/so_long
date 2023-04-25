#include "so_long.h"

static t_map ft_init_vars()
{
    t_map   map;

    map.c = 0;
    map.e = 0;
    map.p = 0;
    map.x = 0;
    map.y = 0;
    return (map);
}
static int  ft_check_border_map(t_vars vars)
{
    int i;

    i = 0;
    while (vars.map[i])
    {
        if (i == 0 && ft_check_long_border(vars.map[i]) == 0)
            break ;
        else if (vars.map[i + 1] == NULL && ft_check_long_border(vars.map[i]) == 0)
            break ;
        else if (ft_check_border(vars.map[i]) == 0)
            break ;
        i++;
    }
    if (vars.map[i] != NULL)
        return (0);
    return (1);
}
static void    ft_check_elements(char **map)
{
    char *char_permit;
    int i;
    int j;

    i = 0;
    char_permit = "10PCEA";
    while (map[i])
    {
        j = 0;
        while(map[i][j] && ft_check_char(map[i][j]))
            j++;
        if (map[i][j] != NULL)
            ft_char_error(map[i][j]);
        i++;
    }
}
static void ft_get_elements(char **map, t_map *vars)
{
    
}

void    ft_check_map(t_vars *vars)
{
    t_map   map_vars;

    map_vars = ft_init_vars();
    ft_check_elements(vars.map);
    ft_get_elements(vars.map, &map_vars);
    if (ft_check_border_map(*vars) == 0)
        ft_error("Error en los bordes del mapa");
}