#include "ft_printf.h"
#include "wat_parse.h"
#include "wutils.h"

void	*wat_element_match(const unsigned char *line,
		const struct s_wat_payload *config)
{
	size_t	line_len;
	size_t	idx;

	idx = 0;
	line_len = ft_strlen((const char *)line);
	while (idx < config->size)
	{
		if (line_len == ft_strlen(config->data[idx].name)
				&& ft_memcmp(line, config->data[idx].name, line_len) == 0)
		{
			if (config->data[idx].length < config->data[idx].max)
			{
				++config->data[idx].length;
				return ((void *)&(config->data[idx]));
			}
			// TODO need better params for failure_warning()
			if (config->data[idx].opt.display_warning_on_failure
					&& config->data[idx].failure_warning != NULL)
				config->data[idx].failure_warning(config->data[idx].max);
			return (NULL);
		}
		++idx;
	}
	return (NULL);
}
