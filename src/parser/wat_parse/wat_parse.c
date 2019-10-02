/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wat_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:48:30 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:48:30 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "ft_printf.h"
#include "wat_parse.h"
#include "wolf3d.h"
#include "wutils.h"

static int		handle_parse_error(const struct s_wat_payload *config,
		const size_t idx_line, const unsigned char *line)
{
	if (config->opt.display_warning_on_failure)
		ft_dprintf(2, "WARNING ! l.%llu:%s\n", idx_line, line);
	if (!config->opt.continue_on_failure)
		return (-1);
	return (0);
}

static size_t	get_end_mark(const size_t idx_line,
		const unsigned char **file, void **end_res)
{
	struct s_wat_element	end;
	struct s_wat_payload	payload;
	size_t					idx_end;

	end.name = "end";
	end.max = 1;
	end.min = 1;
	end.length = 0;
	payload.data = &end;
	payload.size = 1;
	idx_end = idx_line;
	while (file[idx_end] != 0)
	{
		if (file[idx_end][0] == '@'
				&& (*end_res = wat_element_match(file[idx_end] + 1,
						&payload)) != NULL)
			break ;
		++idx_end;
	}
	return (idx_end);
}

static int		wat_parse_at_mark(const unsigned char **file, size_t *idx_line,
		const struct s_wat_element *el)
{
	int									result;
	void								*end_res;
	char								**template;
	size_t								idx_end;

	end_res = NULL;
	idx_end = get_end_mark((const size_t)*idx_line, file, &end_res);
	result = -1;
	if (end_res != NULL)
	{
		template = prepare_template(file,
				(const size_t)(*idx_line + 1), (const size_t)idx_end);
		if (template == NULL)
			return (-1);
		if (el->parse != NULL)
			result = el->parse((const char **)template);
		ft_str2del(template);
	}
	*idx_line = idx_end + ((file[idx_end] != 0) ? 1 : 0);
	return (result);
}

int				wat_parse(const unsigned char **file,
		const struct s_wat_payload *config)
{
	struct s_wat_element	*el;
	int						parse_result;
	size_t					idx_line;
	size_t					tmp;

	idx_line = 0;
	while (file[idx_line] != 0)
	{
		if (file[idx_line][0] == '@'
				&& ft_strncmp((const char *)file[idx_line], "@end", 4) != 0
				&& (el = (struct s_wat_element *)wat_element_match(
						file[idx_line] + 1, config)) != NULL)
		{
			tmp = idx_line;
			if (el == NULL || (parse_result = wat_parse_at_mark(file,
						&idx_line, el)) != 0)
			{
				if (handle_parse_error(config, idx_line, file[tmp]) != 0)
					return (-1);
			}
		}
		else
			++idx_line;
	}
	return (0);
}
