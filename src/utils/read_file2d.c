#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include "wutils.h"

// TODO remove string for using memcpy
#include <string.h>
static size_t	count_char(const char *s, const char c)
{
	size_t	res;
	size_t	idx;

	res = 0;
	idx = 0;
	while (s[idx] != '\0')
	{
		if (s[idx] == c)
			++res;
		++idx;
    }
	return (res);
}

static char		*ft_schr(const char *s, const char c)
{
	while (*s != '\0' && *s != c)
		++s;
	return (*s == c ? (char *)s : NULL);
}

static int		split_line(char **res, char *buf)
{
	size_t	size_line;
	size_t  res_idx;
	char	*new_line_ptr;
	char	*buf_ptr;

	buf_ptr = buf;
	res_idx = 0;
	while ((new_line_ptr = ft_schr(buf_ptr, '\n')) != NULL)
	{
		size_line = (size_t)(new_line_ptr - buf_ptr);
		if ((res[res_idx] = (char *)malloc(sizeof(char) * (size_line + 1)))
				== NULL)
		{
			while (--res_idx != (size_t)-1)
				free(res[res_idx]);
			return (-1);
		}
		memcpy(res[res_idx], buf_ptr, size_line); // TODO replace this by ft_memcpy
		res[res_idx][size_line] = '\0';
		buf_ptr = new_line_ptr + 1;
		++res_idx;
	}
	return (0);
}

unsigned char	**read_file2d(char *filename)
{
	size_t  size_line;
	char	*file;
	char	**res;

	if ((file = read_file(filename)) == NULL)
		return (NULL);
	size_line = count_char(file, '\n');
	res = (char **)malloc(sizeof(char *) * (size_line + 1));
	if (res != NULL)
	{
		res[size_line] = 0;
		if (split_line(res, file) != 0)
		{
			free(res);
			res = NULL;
		}
	}
	free(file);
	return ((unsigned char **)res);
}
