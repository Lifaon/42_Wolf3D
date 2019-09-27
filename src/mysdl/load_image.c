/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 13:11:17 by mlantonn          #+#    #+#             */
/*   Updated: 2019/09/27 13:49:00 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mysdl.h"

static void	copy_32(t_img *img, SDL_Surface *surf)
{
	t_col	*pixels;
	int		i;
	int		j;

	img->w = surf->w;
	img->h = surf->h;
	pixels = (t_col *)surf->pixels;
	j = -1;
	while (++j < surf->h)
	{
		i = -1;
		while (++i < surf->w)
			img->arr[i + j * surf->w] = pixels[i + j * surf->w];
	}
}

static void	copy_24(t_img *img, SDL_Surface *surf)
{
	t_col24	*pixels;
	int		i;
	int		j;

	img->w = surf->w;
	img->h = surf->h;
	pixels = (t_col24 *)surf->pixels;
	j = -1;
	while (++j < surf->h)
	{
		i = -1;
		while (++i < surf->w)
		{
			img->arr[i + j * surf->w].argb.a = 0;
			img->arr[i + j * surf->w].argb.r = pixels[i + j * surf->w].rgb.r;
			img->arr[i + j * surf->w].argb.g = pixels[i + j * surf->w].rgb.g;
			img->arr[i + j * surf->w].argb.b = pixels[i + j * surf->w].rgb.b;
		}
	}
}

_Bool		load_image(const char *path, t_img *img)
{
	SDL_Surface	*surf;

	surf = SDL_LoadBMP(path);
	if (!surf) {
		ft_dprintf(2, "Could not load %s: %s\n", path, SDL_GetError());
		return (EXIT_FAILURE);
	}
	if (surf->w != surf->pitch / 4 && surf->w != surf->pitch / 3)
	{
		ft_dprintf(2, "Could not load %s: format is neither 24 nor 32 bits\n",
			path);
		return (EXIT_FAILURE);
	}
	if (!((img->arr = (t_col *)malloc(sizeof(t_col) * surf->w * surf->h))))
	{
		ft_dprintf(2, "Could not load %s: %s\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	if (surf->w == surf->pitch / 4)
		copy_32(img, surf);
	else
		copy_24(img, surf);
	SDL_FreeSurface(surf);
	return (EXIT_SUCCESS);
}
