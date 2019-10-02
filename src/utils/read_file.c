/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:37:05 by mlantonn          #+#    #+#             */
/*   Updated: 2019/09/17 18:43:57 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "ft_printf.h"

#define MAX_FILE_SIZE 4194304
#define BUFF_SIZE 4096

static char *print_error(char *path, int err_no, char *to_free, int to_close)
{
	ft_dprintf(2, "wolf3d: Could not read '%s': %s\n", path, strerror(err_no));
	if (to_free != NULL)
		free(to_free);
	if (to_close > 0)
		close(to_close);
	return (NULL);
}

static void concat_buff(char *dst, char buff[BUFF_SIZE + 1], ssize_t n_written)
{
	ssize_t i;

	i = -1;
	while (buff[++i])
		dst[n_written + i] = buff[i];
}

char		*read_file(char *filename)
{
	ssize_t	n_read;
	ssize_t	n_written;
	int		fd;
	char	buff[BUFF_SIZE + 1];
	char	*result;

	if ((result = (char *)malloc(sizeof(char) * (MAX_FILE_SIZE + 1))) == NULL)
		return (print_error(filename, errno, NULL, -1));
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (print_error(filename, errno, result, -1));
	n_written = 0;
	while ((n_read = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[n_read] = '\0';
		if (n_written + n_read > MAX_FILE_SIZE)
			return (print_error(filename, EFBIG, result, fd));
		concat_buff(result, buff, n_written);
		n_written += n_read;
	}
	if (n_read < 0)
		return (print_error(filename, errno, result, fd));
	close(fd);
	result[n_written] = '\0';
	return (result);
}
