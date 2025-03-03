/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:47:05 by marvin            #+#    #+#             */
/*   Updated: 2024/12/16 02:50:04 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <bsd/string.h>
# include <ctype.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// Function
int					ft_printf(const char *str, ...);
int					ft_dprintf(int fd, const char *str, ...);
char				*ft_sprintf(const char *str, ...);
char				*get_next_line(int fd);

int					add_string_char_2d(char ***tabb, char *str);
int					count_char(char *str, char char_to_count);
int					join2d(char **join, char **str1, char **str2);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_strlen_2d(char **tab);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_lstsize(t_list *lst);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_printf(const char *str, ...);
int					ft_strcmp(const char *s1, const char *s2);
int					free_split(char **split);
int					is_in_charset(char c, const char *set);

char				**strdup2d(char **str);
char				**str2d_join(char **str1, char **str2);
char				**re_str2djoin(char **str1, char **str2);
char				**strdup2d(char **str);
char				**ft_split(char *s, char *c);

char				*ft_itoa(int n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnew(size_t size);
char				*ft_strstr(char *str, char *to_find);
char				*ft_strtrim(char const *s, char const *sep);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_realloc(char *ptr, int len_realloc);
char				*ft_strcat(char *dest, const char *src);
char				*ft_re_strdup(const char *src);
char				*ft_re_strjoin(const char *s1, const char *s2);
char				*str_join_2d(char **str_2d, char *sep);
char				*str_join_2d_and_free(char **str_2d, char *sep);
char				*read_file(int fd);

void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);

void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl_fd(char *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putstr_fd(char *s, int fd);
void				ft_putstr(char *str);
void				ft_strclr(char *s);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_bzero(void *s, size_t n);
void				ft_lstadd_front(t_list **lst, t_list *neww);
void				ft_lstadd_back(t_list **lst, t_list *neww);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				sort_str2d(char **str);

size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t size);

t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

#endif
