#ifndef BLOCK_H
# define BLOCK_H

# include <stddef.h>
# define BLOCK_SPACE 256

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
	unsigned int	tex_north;
	unsigned int	tex_south;
	unsigned int	tex_east;
	unsigned int	tex_west;
}				t_block;

extern void		block_del(void *a);
extern t_block	*block_get(const unsigned char id);
extern void		*block_new(void);
extern int		block_parse(const char **input);

#endif
