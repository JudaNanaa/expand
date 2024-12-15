/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:18:16 by madamou           #+#    #+#             */
/*   Updated: 2024/12/15 23:47:56 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

t_data *get_data(void)
{
	static t_data data;
	
	return (&data);
}

int get_len_to_next_same_char(char *str, int i, char c)
{
	int len;

	len = 1;
	while (str[i + len] != c)
		len++;
	return (len);
}