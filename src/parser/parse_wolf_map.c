#include <stdlib.h>
#include "ft_printf.h"
#include "wat_parse.h"
#include "wutils.h"

static void	config_payload(struct s_wat_payload *config,
		struct s_wat_element *els)
{
	els[0] = (struct s_wat_element){
		.name = "block",
		.parse = NULL, // TODO parser for @block
		.failure_warning = NULL,
		.max = 30,
		.min = 0,
		.opt.display_warning_on_failure = 0,
		.opt.continue_on_failure = 0
	};
	els[1] = (struct s_wat_element){
		.name = "map",
		.parse = NULL, // TODO parser for @map
		.failure_warning = NULL,
		.max = 1,
		.min = 1,
		.opt.display_warning_on_failure = 0,
		.opt.continue_on_failure = 0
	};
	config->data = els;
	config->size = 2;
	config->opt.continue_on_failure = 1;
	config->opt.display_warning_on_failure = 1;
}

void	*parse_wolf_map(char *filename)
{
	struct s_wat_payload	config;
	struct s_wat_element	els[2];
	void					*res;
	size_t					idx;
	unsigned char			**file;

	file = (unsigned char **)read_file2d(filename);
	if (file == NULL)
		return (NULL);
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
