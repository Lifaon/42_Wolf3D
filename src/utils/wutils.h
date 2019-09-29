#ifndef WUTILS_H
# define WUTILS_H

# include <stddef.h>

extern unsigned long long	ft_atoul_base(const char *s, int base);
extern char					**ft_getline(const char **s1, const char *s2,
		size_t len);
extern int					ft_memcmp(const void *s1, const void *s2, size_t n);
extern void					*ft_memcpy(void *d, const void *s, size_t n);
extern void					*ft_memmove(void *dst, const void *src, size_t len);
extern void					ft_memset(void *b, const int c, const size_t len);
extern void					ft_str2del(char **s);
extern char					*ft_strcdup(const char *s, const int c);
extern char					*ft_strchr(const char *s, const int c);
extern char					*ft_strdup(const char *s);
extern size_t				ft_strlen(const char *s);
extern int					ft_strncmp(const char *s1, const char *s2,
		size_t n);
extern _Bool				is_pow_of2(size_t const n);
extern char					**prepare_template(const unsigned char **f,
		const size_t start, const size_t end);
extern char					*read_file(char *filename);
extern char					**read_file2d(char *filename);
extern size_t				round_up_pow(size_t n);

#endif
