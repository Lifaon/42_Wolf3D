#include "ft_printf.h"
#include "wat_parse.h"

void	*wat_parse(const char **file, const struct s_wat_payload *config)
{
	// void					**res;
	struct s_wat_element	*el;
	size_t					idx_line;

	idx_line = 0;
	while (file[idx_line] != 0)
	{
		if (file[idx_line][0] == '@')
		{
			el = wat_element_match(file[idx_line] + 1, config);
			if (el == NULL)
			{
				if (config->opt.display_warning_on_failure)
					ft_dprintf(2, "WARNING ! line %llu: invalid mark: %s\n",
							idx_line, file[idx_line]);
				if (!config->opt.continue_on_failure)
				{
					// delete all allocated data node
					return (NULL);
				}
			}
			else
			{
				ft_printf("___ found @%s\n", el->name);
				// get @end mark
				// prepare template between @ marks
				// ret = element.parse()
				// append if no null ret append to res else handle failure
			}
		}
		++idx_line;
	}
    // handle returns
	return (NULL);
}
