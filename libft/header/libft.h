/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 09:22:15 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/20 14:27:31 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include "get_next_line.h"
# include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_tree
{
	double			num;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

void				*ft_memset(void *str, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strlenarr(char **array);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t dsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *big, const char *little,\
					size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_atoi(const char *nptr);
int					ft_isspace(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *src);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(char *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)\
					(void *));
int					get_next_line(int fd, char **line);
void				ft_lstdelone_f(void *d);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putendl(char *s);
char				*ft_strndup(const char *src, size_t n);
size_t				ft_strlenchar(const char *s, int ch);
char				*ft_strjnoin(char **s1, char *s2, size_t size);
void				ft_free_tmp(void *tmp);
char				*ft_str_add_char(char *str, size_t count, int ch);
void				ft_freearrpoint(char **nstr, size_t j);
int					ft_min(int value_1, int value_2);
double				*ft_binary_tree_sorting(double *x, int in);
int					ft_strnstrindex(char *big, char *little);
void				ft_free_two_dimensional_arr(char **array);
char				*ft_strndup2(char **src, size_t n);
char				*ft_strcdup2(char **src, int c);
char				**ft_add_element_to_two_dimensional_array(char **array,
							char *elem);
char				*ft_strchr2(const char *s1, const char *s2);
void				ft_delete_an_array_element(char ***array, size_t i);
char 				**create_two_dimensional_array_from_lst(t_list *lst);
char				*ft_strnrchr(const char *s, int c, size_t size);
char				*ft_strrchr2(const char *s1, const char *s2);
char 				*ft_strcpy(char *dest, char *src);
#endif
