#ifndef DICTO_H
# define DICTO_H

# include <stddef.h>
# include "pair.h"

typedef struct	s_dicto_payload
{
	char	*key;
	size_t	max_length;
	int		(*is_valid)(void);
}				t_dicto_payload;

extern t_pairs	*dicto(char **input, t_dicto_payload conf);

#endif
