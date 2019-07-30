#ifndef BLOCK_H
# define BLOCK_H

# include <stddef.h>

enum e_block_type
{
	T_BL_NONE = -1,
	T_BL_VOID,
	T_BL_WALL,
	T_BL_SIZE
};

/**
 * @param type
 * enum e_block_type values
 *
 * @param tex_north
 * north's texture side
 *
 * @param tex_south
 * south's texture side
 *
 * @param tex_east
 * east's texture side
 *
 * @param tex_west
 * west's texture side
 */

typedef struct	s_block
{
	size_t			type;
	unsigned char	*tex_north;
	unsigned char	*tex_south;
	unsigned char	*tex_east;
	unsigned char	*tex_west;
}				t_block;

void			block_del(void *a);
void			*block_new(void);
void			*block_parse(const char **input);

#endif
