/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:06:54 by marvin            #+#    #+#             */
/*   Updated: 2025/03/10 18:00:51 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <time.h>

static int	ft_count_word(char const *s, char *c)
{
	int	i;
	int	cpt;

	cpt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && is_in_charset(s[i], c))
			i++;
		while (s[i] && !is_in_charset(s[i], c))
			i++;
		cpt++;
	}
	if (i == 0)
		return (0);
	if (is_in_charset(s[i - 1], c))
		cpt--;
	return (cpt);
}

static int	ft_split_words(char **split, char const *s, char *c)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	while (s[i])
	{
		while (is_in_charset(s[i], c) && s[i])
			i++;
		j = 0;
		while (!is_in_charset(s[i + j], c) && s[i + j])
			j++;
		if (!is_in_charset(s[i + j - 1], c))
		{
			split[index] = ft_substr(s, i, j);
			if (split[index] == NULL)
				return (free_split(split), 0);
			index++;
			i += j;
		}
	}
	split[index] = 0;
	return (1);
}

char	**ft_split(char *s, char *c)
{
	char	**split;

	if (!s)
	{
		split = malloc(sizeof(char *));
		if (!split)
			return (NULL);
		split[0] = NULL;
		return (split);
	}
	split = malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (split == NULL)
		return (NULL);
	if (ft_split_words(split, s, c) == 0)
		return (NULL);
	return (split);
}

// int	main(void)
// {
// 	char **test;
// 	int i;

// 	i = 0;
// 	test = ft_split("KEY=VALUE", "=");
// 	if (test == NULL)
// 	{
// 		printf("tout est null\n");
// 		return (0);
// 	}
// 	char *oui = test[0];
// 	char *non = test[1];
// 	if (test[i] == NULL)
// 		printf("%u", 42);
// 	free(test);
// 	printf("oui == %s\n", oui);
// 	printf("non == %s\n", non);
// 	free(oui);
// 	free(non);
// }
