#ifndef ENV_H
# define ENV_H

# include "array.h"
# include "pair.h"

# define ENV_SPACE 1

typedef t_pairs t_env;

extern void	env_del(void *a);
extern char	*env_get(const char *key);
extern void	*env_new(void);
extern int	env_parse(const char **input);

#endif
