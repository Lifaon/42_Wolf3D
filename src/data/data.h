#ifndef DATA_H
# define DATA_H

# include <stddef.h>
# include "type.h"

enum e_data_type
{
	T_DA_NONE = -1,
	T_DA_MAP,
	T_DA_BLOCK,
	T_DA_TEXTURE,
	T_DA_SIZE
};

typedef t_type	t_data;

void			data_del(t_data **a);
t_data			*data_new(const size_t type, const size_t sub_type);

#endif
