/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 02:28:49 by madamou           #+#    #+#             */
/*   Updated: 2024/12/15 03:51:25 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"

int main(int argc, char **argv)
{
	int i;
	char *ptr;

	i = 0;
	(void)argv;
	(void)argc;
	while (i < 100)
	{
		ptr = ft_malloc(100);
		if (i % 2 != 0)
			lock(ptr);
		i++;
	}
	soft_clear();
	clear_all();
}