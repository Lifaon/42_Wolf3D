#include <stdlib.h>
#include "array.h"
#include "block.h"
#include "ft_printf.h"
#include "map.h"
#include "singletone.h"
#include "texture.h"
#include "wat_parse.h"
#include "wutils.h"

static void	config_payload(struct s_wat_payload *config,
		struct s_wat_element *els)
{
	els[0] = (struct s_wat_element){
		.name = "block",
		.parse = &block_parse,
		// .parse = NULL,
		.failure_warning = NULL,
		.max = 256,
		.min = 0,
		.length = 0,
		.opt.display_warning_on_failure = 0,
		.opt.continue_on_failure = 0
	};
	els[1] = (struct s_wat_element){
		.name = "map",
		.parse = &map_parse,
		.failure_warning = NULL,
		.max = 1,
		.min = 1,
		.length = 0,
		.opt.display_warning_on_failure = 0,
		.opt.continue_on_failure = 0
	};
	els[2] = (struct s_wat_element){
		.name = "texture",
		.parse = &texture_parse,
		.failure_warning = NULL,
		.max = 64,
		.min = 0,
		.length = 0,
		.opt.display_warning_on_failure = 0,
		.opt.continue_on_failure = 0
	};
	config->data = els;
	config->size = 3;
	config->opt.continue_on_failure = 1;
	config->opt.display_warning_on_failure = 1;
}

int		parse_wolf_map(char *filename)
{
	struct s_wat_payload	config;
	struct s_wat_element	els[3];
	int						res;
	size_t					idx;
	unsigned char			**file;

	file = (unsigned char **)read_file2d(filename);
	if (file == NULL)
	{
		ft_dprintf(2, "error: invalid file or run out of memory\n");
		return (-2);
	}
	if (*singletone_block() == NULL || *singletone_texture() == NULL)
	{
		idx = 0;
		while (file[idx] != 0)
		{
			free(file[idx]);
			++idx;
		}
		free(file);
		singletone_block_del();
		singletone_texture_del();
		ft_dprintf(2, "error: run out of memory during parsing\n");
		return (-1);
	}
	idx = 0;
	while (file[idx] != 0)
	{
		ft_printf("%s\n", file[idx]);
		++idx;
	}
	config_payload(&config, els);
	res = wat_parse((const unsigned char **)file, &config);
	idx = 0;
	while (file[idx] != 0)
	{
		free(file[idx]);
		++idx;
	}
	free(file);
	return (res);
}
