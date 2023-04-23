#include "so_long.h"
#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
int	main(void)
{
	char *str = "hola que tal";
	printf("\033[1;31m🛑ERROR \033[0m");
} 