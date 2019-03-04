/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:40:27 by edhommee          #+#    #+#             */
/*   Updated: 2018/03/03 19:10:23 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <sys/stat.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include <wchar.h>

int					get_next_line(const int fd, char **line);
int					ft_printf(const char *format, ...);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
char				*ft_itoa_base(uintmax_t n, int base);
int					get_stmode(char *pathfile, char opt, int fn);
char				*ft_getenv(char *name);
int					ft_unsetenv(const char *name);
int					ft_putenv(char *str);
int					ft_setenv(const char *name, const char *value, int ov);

void				ft_putchar(char c);
void				ft_putstr(const char *s);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_puttab(char **tab);

size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strcjoin(char const *s1, const char *s2, char c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strnew(size_t size);
char				**ft_strsplit(char const *s, char c);
char				*ft_wchartoa(wint_t wint);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
char				*ft_reverse(char *str, int size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,\
					size_t len);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strtrim(char const *s);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strlowcase(char *s);

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy_rev(void *dst, const void *src, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_swap_star(void **one, void **two);

int					ft_nbrlen(int nbr);
char				**ft_tabdup(char **tab);
char				**ft_tabndup(char **tab, size_t n);
char				**ft_tabnew(int size);
void				ft_tabdel(char ***tab);
size_t				ft_tablen(char **tab);
char				**ft_tabcpy(char **dest, char **src);
char				**ft_tabndup(char **tab, size_t n);

int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isnumber(char *src);

#endif
