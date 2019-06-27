#include "array.h"
#include "ft_printf.h"

void	array_show(t_array *a)
{
	if (a == NULL)
		ft_printf("<A> => (NULL)\n");
	else
	{
		ft_printf("<A> => (\n");
		ft_printf("  p: %p\n", a->p);
		ft_printf("  length: %llu\n", a->length);
		ft_printf("  capacity: %llu\n", a->capacity);
		ft_printf("  sizeof: %llu\n", a->p_size);
		ft_printf(")\n\n");
	}
}
