/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 02:39:22 by madamou           #+#    #+#             */
/*   Updated: 2024/12/16 02:42:55 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

char	**split_first_value(char *str, char sep)
{
	int		i;
	int		j;
	char	**result;

	i = 0;
	j = 0;
	result = ft_malloc(sizeof(char *) * 3);
	if (!result)
		return (NULL);
	while (str[i] && str[i] != sep)
		i++;
	result[0] = ft_substr(str, 0, i);
	if (str[i] == sep)
	{
		while (str[j + i + 1])
			j++;
		result[1] = ft_malloc(sizeof(char) * (j + 1));
		if (!result[1])
			return (NULL);
		ft_strcpy(result[1], &str[i + 1]);
	}
	else
		result[1] = NULL;
	result[2] = NULL;
	return (result);
}

t_env	*init_env(char *envp)
{
	t_env	*new;
	char	**split;

	new = ft_calloc(sizeof(t_env), 1);
	if (!new)
		return (NULL);
	split = split_first_value(envp, '=');
	if (!split)
		return (ft_free(new), NULL);
	new->key = split[0];
	new->value = split[1];
	ft_free(split);
	lock(new);
	lock(new->key);
	lock(new->value);
	return (new);
}

void	add_back_env(t_env **env, t_env *new)
{
	t_env	*current;

	current = *env;
	if (*env == NULL)
		*env = new;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
		new->prev = current;
	}
}

t_env	*env_in_struct(char **envp)
{
	int		i;
	t_env	*env;
	t_env	*new;

	i = 0;
	env = NULL;
	while (envp && envp[i])
	{
		new = init_env(envp[i]);
		if (!new)
			return (NULL);
		add_back_env(&env, new);
		i++;
	}
	return (env);
}