#ifndef WAT_PARSE_H
# define WAT_PARSE_H

# include <stdlib.h>

struct s_wat_element_opt
{
	_Bool	display_warning_on_failure;
	_Bool	continue_on_failure;
};

struct s_wat_element
{
	char						*name;
	void						*(*parse)(const char **);
	void						(*delete_node)(void *);
	void						(*failure_warning)(const int);
	size_t						max;
	size_t						min; // min > 0 then mandatory element
	size_t						length;
	struct s_wat_element_opt	opt;
};

struct s_wat_payload
{
	struct s_wat_element		*data;
	size_t						size;
	struct s_wat_element_opt	opt;
};

int		wat_parse(const unsigned char **file,
		const struct s_wat_payload *config);
void	*wat_element_match(const unsigned char *line,
		const struct s_wat_payload *config);

#endif
