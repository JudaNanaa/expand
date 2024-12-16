/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 04:05:52 by madamou           #+#    #+#             */
/*   Updated: 2024/12/16 03:06:09 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand/expand.h"
#include "libft/libft.h"

int main(int argc, char **argv, char **envp)
{
	int i;
	t_data *data;

	(void)argc;
	if (argc < 2)
	{
		ft_printf("error pas assez d'args\n");
		return 1;
	}
	data = get_data();
	data->envp = envp;
	data->env = env_in_struct(envp);
	argv = expand(&argv[1]);
	i = 0;
	while (argv[i])
	{
		ft_printf("expand == %s\n", argv[i]);	
		i++;
	}
}