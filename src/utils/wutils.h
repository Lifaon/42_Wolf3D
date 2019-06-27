#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *d, const void *s, size_t n);
size_t	ft_strlen(const char *s);
char	*read_file(char *filename);
char	**read_file2d(char *filename);

#endif
