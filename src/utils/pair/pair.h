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

char			*pair_key_new(const char *s);
char			*pair_value_new(const char *s);

extern void		pair_delete(t_pair **a);
extern t_pair	*pair_new(void);
extern t_pair	*pair_parse(t_pair *a, const char *s);

#endif
