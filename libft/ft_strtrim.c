/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:07:11 by marvin            #+#    #+#             */
/*   Updated: 2024/12/16 02:50:04 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	malloc_size(char const *s1, char const *sep)
{
	int	i;
	int	j;
	int	len_s;

	len_s = ft_strlen(s1);
	i = 0;
	j = 0;
	while (is_in_charset(s1[i], sep) == 1 && s1[i])
		i++;
	while (len_s - 1 - j >= 0 && is_in_charset(s1[len_s - 1 - j], sep) == 1)
		j++;
	if (len_s - (i + j) <= 0)
		return (0);
	return (len_s - (i + j));
}

static void	ft_fill_str(char const *s1, char *str, char const *sep)
{
	int	i;
	int	j;
	int	k;
	int	len_s;

	len_s = ft_strlen(s1);
	k = 0;
	i = 0;
	j = 0;
	while (is_in_charset(s1[i], sep) == 1 && s1[i])
		i++;
	while (len_s - 1 - j >= 0 && is_in_charset(s1[len_s - 1 - j], sep) == 1)
		j++;
	while (i < len_s - j)
		str[k++] = s1[i++];
	str[k] = '\0';
}

char	*ft_strtrim(char const *s1, char const *sep)
{
	char	*str;

	str = malloc(sizeof(char) * (malloc_size(s1, sep) + 1));
	if (str == NULL)
		return (NULL);
	ft_fill_str(s1, str, sep);
	return (str);
}

// int main(void)
// {
// 	char *strtrim;

//     char s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
//     if (!(strtrim = ft_strtrim(s1, " ")))
//         printf("NULL");
//     else
//         printf("%s\n", strtrim);
//     if (strtrim == s1)
//         printf("\nA new string was not returned");

// }