#include <stdlib.h>
#include "array.h"
#include "texture.h"
#include "wutils.h"

t_texture	***singletone_texture(void)
{
	static t_texture	**a = NULL;

	if (a == NULL)
	{
		a = malloc(sizeof(t_texture *) * 256);
		if (a != NULL)
			ft_memset((void *)a, 0, sizeof(t_texture *) * 256);
	}
	return (&a);
}

void	singletone_texture_del(void)
{
	t_texture	***a;
	size_t	idx;

	a = singletone_texture();
	if (*a != NULL)
	{
		idx = 0;
		while (idx < TEXTURE_SPACE)
		{
			free((*a)[idx]);
			++idx;
		}
		free(*a);
		*a = NULL;
	}
}
