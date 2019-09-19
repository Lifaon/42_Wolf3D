#include "array.h"
#include "ft_printf.h"
#include "wat_parse.h"
#include "wolf3d.h"
#include "wutils.h"

#include "block.h"
#include <unistd.h>
void	*wat_parse_at_mark(const unsigned char **file, size_t *idx_line,
		const struct s_wat_element *el)
{
	static struct s_wat_element			end[1] = {
		[0] = {
			.name = "end",
			.max = 1,
			.min = 1,
			.length = 0
		}
	};
	static const struct s_wat_payload	payload = {
		.data = end,
		.size = 1
	};
	void								*result;
	void								*end_res;
	char								**template;
	size_t								idx_end;

	idx_end = *idx_line;
	while (file[idx_end] != 0)
	{
		(*end).length = 0;
		if (file[idx_end][0] == '@'
				&& (end_res = wat_element_match(file[idx_end] + 1, &payload)) != NULL)
			break ;
		++idx_end;
	}
	result = NULL;
	if (end_res != NULL)
	{
		template = prepare_template(file,
				(const size_t)(*idx_line + 1), (const size_t)idx_end);
		if (template == NULL)
			return (NULL);
		if (el->parse != NULL)
		{
			ft_printf("___ start parse [%s]\n", el->name);
			result = el->parse((const char **)template);
			ft_printf("___ finish parse ??\n");
		}
		else
			ft_dprintf(2, "parsing == NULL\n"); // TODO to remove -> debug purpose
		ft_str2del(template);
	}
	*idx_line = idx_end + ((file[idx_end] != 0) ? 1 : 0);
	return (result);
}

int		wat_parse(const unsigned char **file,
		const struct s_wat_payload *config)
{
	void					*parse_result;
	struct s_wat_element	*el;
	size_t					idx_line;

	ft_printf("Processing parser !\n");
	idx_line = 0;
	while (file[idx_line] != 0)
	{
		if (file[idx_line][0] == '@')
		{
			size_t	tmp = idx_line;
			el = (struct s_wat_element *)wat_element_match(file[idx_line] + 1, config);
			if (el == NULL || (parse_result = wat_parse_at_mark(file, &idx_line, el)) == NULL)
			{
				ft_printf("___ fail? ??\n");
				if (config->opt.display_warning_on_failure)
					ft_dprintf(2, "WARNING ! Around l.%llu:%s\n", idx_line, file[tmp]);
				if (!config->opt.continue_on_failure)
				{
					return (-1);
				}
			}
			else
			{
				ft_printf("___ found @%s\n", el->name);
			}
		}
		else
			++idx_line;
	}
	return (0);
}
