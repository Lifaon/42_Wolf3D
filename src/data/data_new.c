#include <stdlib.h>
#include "data.h"
#include "block.h"
#include "map.h"
#include "texture.h"

t_data	*data_new(const size_t type, const size_t sub_type)
{
	static void	*(*node_new[T_DA_SIZE])(const size_t) = {
		[T_DA_MAP] = &map_new,
		[T_DA_BLOCK] = &block_new,
		[T_DA_TEXTURE] = &texture_new
	};
	t_data		*res;

	res = NULL;
	if (type < T_DA_SIZE && (res = (t_data *)malloc(sizeof(*res))) != NULL)
	{
		res->type = type;
		if ((res->node = node_new[type](sub_type)) == NULL)
		{
			free(res);
			return (NULL);
		}
	}
	return (res);
}
