#ifndef PAIR_H
# define PAIR_H

# include <stddef.h>

typedef struct	s_pair
{
	char	*key;
	char	*value;
}				t_pair;

typedef struct	s_pairs
{
	t_pair	**p;
	size_t	length;
	size_t	capacity;
	size_t	p_size;
}				t_pairs;

#endif
