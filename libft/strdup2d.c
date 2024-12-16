/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 02:52:33 by madamou           #+#    #+#             */
/*   Updated: 2024/12/16 02:13:58 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**strdup2d(char **str)
{
	char	**res;
	int		i;

	res = malloc(sizeof(char *) * (ft_strlen_2d(str) + 1));
	if (res == NULL)
		return (NULL);
	i = -1;
	while (str[++i] != NULL)
	{
		res[i] = ft_strdup(str[i]);
		if (res[i] == NULL)
			return (free_split(res), NULL);
	}
	res[i] = NULL;
	return (res);
}
