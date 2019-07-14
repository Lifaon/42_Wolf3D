#include "array.h"
#include "ft_printf.h"
#include "wat_parse.h"
#include "wolf3d.h"

void	*wat_parse_at_mark(void)
{
	// get @end mark
	// prepare template between @ marks
	// ret = element.parse()
	// append if no null ret append to res else handle failure
	return (NULL);
}

void	*wat_parse(const unsigned char **file,
		const struct s_wat_payload *config)
{
	t_datas					*result;
	void					*parse_result;
	struct s_wat_element	*el;
	size_t					idx_line;

	result = (t_datas *)array_new(sizeof(t_data));
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
					array_delete((t_array *)result, &data_del);
					return (NULL);
				}
			}
			else
			{
				parse_result = wat_parse_at_mark();
				if (parse_result != NULL)
				{
					if (array_push((t_array *)result, parse_result, 1) == EXIT_FAILURE)
					{
						array_delete((t_array *)result, &data_del);
						return (NULL);
					}
				}
				else
				{
					if (config->opt.display_warning_on_failure)
					{
						// print error reason
					}
					if (!config->opt.continue_on_failure)
					{
						array_delete((t_array *)result, &data_del);
						return (NULL);
					}
				}
				ft_printf("___ found @%s\n", el->name);
			}
		}
		++idx_line;
	}
    // handle returns
	return (NULL);
}
