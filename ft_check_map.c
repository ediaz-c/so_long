#include "so_long.h"
static char	*ft_read_file(const char *path)
{
	int		fd;
	char	*line;
	char	*all_line;
	char	*tmp;

	all_line = ft_strdup("");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error("Error al abrir el archivo");
	while (line)
	{
		line = get_next_line(fd);
		tmp = all_line;
		all_line = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
	}
	return (all_line);
}
static void	ft_check_elements(t_map map)
{
	
}
static void	ft_read_map(char **map)
{
	t_map	var_map;
}

char	**ft_check_map(const char *path)
{
	char 	**map;
	char	*all_line;
	
	all_line = ft_read_file(path);
	if (all_line[0] == '\0')
		ft_error("Archivo vacio");
	map = ft_split(all_line, '\n');
	if (map == NULL)
		ft_error("Error leyendo el mapa");
	free(all_line);
	ft_check_elements(map);
	return (map);
}