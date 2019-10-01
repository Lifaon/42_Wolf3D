#include <stdlib.h>
#include "array.h"
#include "block.h"
#include "ft_printf.h"
#include "map.h"
#include "singletone.h"
#include "texture.h"
#include "wat_parse.h"
#include "wutils.h"

static void	config_payload2(struct s_wat_element *els)
{
	els[2] = (struct s_wat_element){
		.name = "texture",
		.parse = &texture_parse,
		.failure_warning = NULL,
		.max = 256,
		.min = 0,
		.length = 0,
		.opt.display_warning_on_failure = 0,
		.opt.continue_on_failure = 0
	};
	els[3] = (struct s_wat_element){
		.name = "env",
		.parse = &env_parse,
		.failure_warning = NULL,
		.max = 1,
		.min = 1,
		.length = 0,
		.opt.display_warning_on_failure = 0,
		.opt.continue_on_failure = 0
	};
}

static void	config_payload(struct s_wat_payload *config,
		struct s_wat_element *els)
{
	els[0] = (struct s_wat_element){
		.name = "block",
		.parse = &block_parse,
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
	config_payload2(els);
	config->data = els;
	config->size = 4;
	config->opt.continue_on_failure = 0;
	config->opt.display_warning_on_failure = 1;
}

int		check_meta(const size_t length, const size_t min, const size_t max, const char *s)
{
	(void)s;
	return (min <= length && length <= max ? 0 : 1);
}

int		parse_wolf_map(char *filename)
{
	struct s_wat_payload	config;
	struct s_wat_element	els[4];
	int						res;
	unsigned char			**file;

	file = (unsigned char **)read_file2d(filename);
	if (file == NULL)
	{
		ft_dprintf(2, "error: invalid file or run out of memory\n");
		return (-2);
	}
	config_payload(&config, els);
	res = wat_parse((const unsigned char **)file, &config);
	ft_str2del((char **)file);
	if (check_meta(block_length(), 0, 256, "BLOCK") != 0
			|| check_meta(env_length(), 1, 1, "ENV") != 0
			|| check_meta(map_length(), 1, 1, "MAP") != 0
			|| check_meta(texture_length(), 0, 256, "TEXTURE") != 0)
		return (-42);
	return (res);
}
