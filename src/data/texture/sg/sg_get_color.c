#include "sg.h"

unsigned int	texture_sg_get_color(const void *t,
		const double y, const double x)
{
	t_texture_sg	*s;

	(void)x;
	(void)y;
	s = (t_texture_sg *)t;
	return (s->color);
}
