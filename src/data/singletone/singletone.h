#ifndef SINGLETONE_H
# define SINGLETONE_H

# include "block.h"
# include "texture.h"

extern t_block		***singletone_block(void);
extern void			singletone_block_del(void);
extern t_texture	***singletone_texture(void);
extern void			singletone_texture_del(void);

#endif
