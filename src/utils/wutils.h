#ifndef WUTILS_H
# define WUTILS_H

# include <stddef.h>

extern int		ft_memcmp(const void *s1, const void *s2, size_t n);
extern void		*ft_memcpy(void *d, const void *s, size_t n);
extern void		*ft_memmove(void *dst, const void *src, size_t len);
extern size_t	ft_strlen(const char *s);
extern _Bool	is_pow_of2(size_t const n);
extern char		*read_file(char *filename);
extern char		**read_file2d(char *filename);
extern size_t	round_up_pow(size_t n);

#endif
