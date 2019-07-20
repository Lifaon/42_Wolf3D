#include <stdlib.h>
#include "sg.h"

void	*texture_sg_new(void)
{
	t_texture_sg	*res;

	if ((res = (t_texture_sg *)malloc(sizeof(*res))) != NULL)
	{
		res->color = 0;
	}
	return ((void *)res);
}
