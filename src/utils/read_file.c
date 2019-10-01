/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:53:01 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:53:02 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

char	*read_file(char *filename)
{
	struct stat	st;
	int			fd;
	char		*res;

	if (stat(filename, &st) != 0)
		return (NULL);
	if (!S_ISREG(st.st_mode) || !(st.st_mode & S_IRUSR) || st.st_size <= 0)
		return (NULL);
	res = NULL;
	if ((fd = open(filename, O_RDONLY)) > 0)
	{
		if ((res = (char *)malloc((size_t)st.st_size + 1)) != NULL)
		{
			if (read(fd, (void *)res, st.st_size) == st.st_size)
				res[st.st_size] = '\0';
			else
			{
				free(res);
				res = NULL;
			}
		}
	}
	close(fd);
	return (res);
}
