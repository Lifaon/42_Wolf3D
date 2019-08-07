#ifndef DICTO_H
# define DICTO_H

# include <stddef.h>
# include "pair.h"

typedef struct	s_dicto_element
{
	char	*key;
	size_t	length;
	size_t	max_length;
	int		(*is_valid)(void);
}				t_dicto_element;

typedef struct	s_dicto_payload
{
	t_dicto_element	*els;
	size_t			length;
	int				(*is_valid)(void);
}				t_dicto_payload;

extern t_pairs	*dicto(const char **input, const t_dicto_payload *conf);

#endif
