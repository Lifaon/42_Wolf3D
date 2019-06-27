#include "ft_printf.h"
#include "wat_parse.h"
#include "wutils.h"

void	*wat_element_match(const char *line,
		const struct s_wat_payload *config)
{
	size_t	line_len;
	size_t	idx;

	idx = 0;
    line_len = ft_strlen(line);
	while (idx < config->size)
	{
		if (line_len == ft_strlen(config->data[idx].name)
				&& ft_memcmp(line, config->data[idx].name, line_len) == 0)
			return ((void *)&(config->data[idx]));
		++idx;
	}
	return (NULL);
}
