#include "get_next_line.h"

int	main(void)
{
	char *line;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break;
		printf("%s", line);
		free(line);
	}
}
