/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:19:31 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/11 19:57:30 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_libftlist
{
	void				*content;
	struct s_libftlist	*next;
}						t_libftlist;

int			ft_atoi(const char *nptr);
void		*ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dest, const char *src, size_t siz);
size_t		ft_strlcpy(char *dest, const char *src, size_t siz);
size_t		ft_strlen(const char *str);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

t_libftlist	*ft_lstnew(void *content);
void		ft_lstadd_front(t_libftlist **lst, t_libftlist *new);
int			ft_lstsize(t_libftlist *lst);
t_libftlist	*ft_lstlast(t_libftlist *lst);
void		ft_lstadd_back(t_libftlist **lst, t_libftlist *new);
void		ft_lstdelone(t_libftlist *lst, void (*del)(void *));
void		ft_lstclear(t_libftlist **lst, void (*del)(void *));
void		ft_lstiter(t_libftlist *lst, void (*f)(void *));
t_libftlist	*ft_lstmap(t_libftlist *lst, void *(*f)(void *),
				void (*del)(void *));

#endif
