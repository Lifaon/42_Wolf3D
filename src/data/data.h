#ifndef DATA_H
# define DATA_H

# include <stddef.h>

enum e_data_type
{
	T_DA_NONE = -1,
	T_DA_MAP,
	T_DA_BLOCK,
	T_DA_SIZE
};

/**
 * @param type
 * enum e_data_type values
 *
 * @param node
 * ptr to the struct of @param type
 */

typedef struct	s_data
{
	size_t	type;
	void	*node;
}				t_data;

void			data_del(t_data *a);
t_data			*data_new(const size_t type);

#endif
