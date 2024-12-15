/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 04:05:52 by madamou           #+#    #+#             */
/*   Updated: 2024/12/15 23:07:46 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand/expand.h"

int main(int argc, char **argv, char **envp)
{
	int i;
	t_data *data;

	(void)argc;
	data = get_data();
	data->envp = envp;
	argv = expand(&argv[1]);
	i = 0;
	while (argv[i])
	{
		ft_printf("expand == %s\n", argv[i]);	
		i++;
	}
}