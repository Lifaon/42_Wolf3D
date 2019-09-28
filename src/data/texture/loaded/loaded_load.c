#include "mysdl.h"
#include "loaded.h"
#include "pair.h"

#include "ft_printf.h"
static void	copy32(t_texture_loaded *loaded, SDL_Surface *surf)
{
	t_col	*pixels;
	int		i;
	int		j;

	loaded->x = surf->w;
	loaded->y = surf->h;
	pixels = (t_col *)surf->pixels;
	j = 0;
	while (j < surf->h)
	{
		i = 0;
		while (i < surf->w)
		{
			loaded->ibuf[i + j * surf->w] = pixels[i + j * surf->w].c;
			++i;
		}
		++j;
	}
}

static void	copy24(t_texture_loaded *loaded, SDL_Surface *surf)
{
	struct s_col24	*pixels;
	int				i;
	int				j;

	loaded->x = surf->w;
	loaded->y = surf->h;
	pixels = (struct s_col24 *)surf->pixels;
	j = 0;
	while (++j < surf->h)
	{
		i = 0;
		while (++i < surf->w)
		{
			loaded->cbuf[i + j * 4 + 3] = 0;
			loaded->cbuf[i + j * 4 + 2] = pixels[i + j * surf->w].r;
			loaded->cbuf[i + j * 4 + 1] = pixels[i + j * surf->w].g;
			loaded->cbuf[i + j * 4] = pixels[i + j * surf->w].b;
			++i;
		}
		++j;
	}
}

int			texture_loaded_load(void *a, t_pairs *pairs)
{
	SDL_Surface			*surface;
	t_texture_loaded	*load;
	unsigned char		*s;

	load = (t_texture_loaded *)a;
	s = (unsigned char *)pair_get(pairs, "file");
	if (s == NULL || s[0] == '\0')
		return (-3);
	surface = SDL_LoadBMP((const char *)s);
	if (surface == NULL)
		return (-2);
	if (surface->w != surface->pitch / 4 && surface->w != surface->pitch / 3)
	{
		SDL_FreeSurface(surface);
		return (-3);
	}
	load->ibuf = (unsigned int *)malloc(sizeof(int) * surface->w * surface->h);
	if (load->ibuf == NULL)
	{
		SDL_FreeSurface(surface);
		return (-4);
	}
	(surface->w == surface->pitch / 4) ? copy32(load, surface)
		: copy24(load, surface);
	SDL_FreeSurface(surface);
	ft_printf("texture file name -> '%s'\n", s);
	return (0);
}
