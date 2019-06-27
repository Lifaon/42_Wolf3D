#include <stdlib.h>
#include "ft_printf.h"
#include "wat_parse.h"
#include "wutils.h"

static void	config_payload(struct s_wat_payload *config,
		struct s_wat_element *els)
{
	els[0].name = "block";
	els[0].parse = NULL; // TODO parser for @block
	els[0].failure_warning = NULL;
	els[0].max = 30;
	els[0].min = 0;
	els[0].opt.display_warning_on_failure = 0;
	els[0].opt.continue_on_failure = 0;
	els[1].name = "map";
	els[1].parse = NULL; // TODO parser for @map
	els[1].failure_warning = NULL;
	els[1].max = 1;
	els[1].min = 1;
	els[1].opt.display_warning_on_failure = 0;
	els[1].opt.continue_on_failure = 0;
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
	char					**file;

	file = read_file2d(filename);
	if (file == NULL)
		return (NULL);
	idx = 0;
	while (file[idx] != 0)
	{
		ft_printf("%s\n", file[idx]);
		++idx;
	}
	config_payload(&config, els);
	res = wat_parse((const char **)file, &config);
	idx = 0;
	while (file[idx] != 0)
	{
		free(file[idx]);
		++idx;
	}
	free(file);
	return (res);
}
