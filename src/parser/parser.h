/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:21:40 by mlantonn          #+#    #+#             */
/*   Updated: 2019/09/25 11:05:31 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "ft_printf.h"

# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>

# define MAX_FILE_SIZE 4194304
# define BUFF_SIZE 4096

typedef struct	s_vec
{
	double		x;
	double		y;
}				t_vec;

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_cam
{
	t_vec		pos;
	t_pos		pos_i;
	t_vec		dir;
	t_vec		plane;
}				t_cam;

char	*read_file(char *path);

int		parse_wolf_map(char *filename);
#endif
