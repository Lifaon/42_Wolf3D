#include "array.h"
#include "ft_printf.h"
#include "wat_parse.h"
#include "wolf3d.h"
#include "wutils.h"

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
			result = el->parse((const char **)template);
		else
			ft_dprintf(2, "parsing == NULL\n"); // TODO to remove -> debug purpose
		ft_str2del(template);
	}
	*idx_line = idx_end + ((file[idx_end] != 0) ? 1 : 0);
	return (result);
}

void	*wat_parse(const unsigned char **file,
		const struct s_wat_payload *config)
{
	t_datas					*result;
	void					*parse_result;
	struct s_wat_element	*el;
	size_t					idx_line;

	ft_printf("Processing parser !\n");
	result = (t_datas *)array_new(sizeof(t_data *));
	idx_line = 0;
	while (file[idx_line] != 0)
	{
		if (file[idx_line][0] == '@')
		{
			size_t	tmp = idx_line;
			el = (struct s_wat_element *)wat_element_match(file[idx_line] + 1, config);
			if (el == NULL || (parse_result = wat_parse_at_mark(file, &idx_line, el)) == NULL)
			{
				if (config->opt.display_warning_on_failure)
					ft_dprintf(2, "WARNING ! Around l.%llu:%s\n", idx_line, file[tmp]);
				if (!config->opt.continue_on_failure)
				{
					array_delete((t_array *)result, &data_del);
					return (NULL);
				}
			}
			else
			{
				if (array_push((t_array *)result, (void *)&parse_result, 1) == EXIT_FAILURE)
				{
					array_delete((t_array *)result, &data_del);
					return (NULL);
				}
				ft_printf("___ found @%s\n", el->name);
			}
		}
		else
			++idx_line;
	}
	return ((void *)result);
}
