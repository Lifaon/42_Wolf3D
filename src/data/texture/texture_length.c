#include "texture.h"
#include "singletone.h"

size_t	texture_length(void)
{
	t_texture	**b;
	size_t		i;
	size_t		c;

	b = *singletone_texture();
	i = 0;
	c = 0;
	while (i < TEXTURE_SPACE)
	{
		if (b[i] != NULL)
			++c;
		++i;
	}
	return (c);
}
