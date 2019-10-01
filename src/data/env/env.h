/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:49:31 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:49:32 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "array.h"
# include "pair.h"

# define ENV_SPACE 1

typedef t_pairs t_env;

extern void		env_del(void *a);
extern char		*env_get(const char *key);
extern void		*env_new(void);
extern int		env_parse(const char **input);
extern size_t	env_length(void);

#endif
