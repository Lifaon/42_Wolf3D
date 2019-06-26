#include <stdlib.h>
#include "wutils.h"

int		parse_wolf_map(char *filename)
{
	char	*file;

	file = read_file(filename);
	if (file == NULL)
		return (-1);
	// insert parsing
	free(file);
	return (0);
}
