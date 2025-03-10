/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:59:43 by madamou           #+#    #+#             */
/*   Updated: 2025/03/10 18:04:39 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

bool is_variable_char(char c)
{
	if (ft_isalnum(c) || c == '_')
		return true;
	return false;
}

void add_until_dollard(char **dest, char *str, int *i)
{
	int len;
	char *substr;

	len = 0;
	while (str[*i + len] && str[*i + len] != '$')
		len++;
	substr = ft_substr(str, *i, len);
	*dest = ft_re_strjoin(*dest, substr);
	ft_free(substr);
	*i += len;
}

char *extract_variable(char *str, int *start)
{
	int len;
	char *variable;

	len = 0;
	(*start)++;
	if (str[*start] == '?')
		return ((*start)++, ft_strdup("?"));
	while (str[*start + len] && is_variable_char(str[*start + len]))
		len++;
	if (len == 0)
		return (ft_strdup("$"));
	variable = ft_substr(str, *start, len);
	*start += len;
	return variable;
}

char *expand_variable(char *variable)
{
	t_data *data;
	t_env *env;

	data = get_data();
	env = data->env;
	if (ft_strcmp(variable, "$") == 0)
		return (variable);
	if (ft_strcmp(variable, "?") == 0)
		return (ft_free(variable), ft_itoa(data->status));
	while (env)
	{
		if (ft_strcmp(env->key, variable) == 0)
			return (ft_free(variable), ft_strdup(env->value));
		env = env->next;
	}
	ft_free(variable);
	return ft_strdup("");
}

char *expand_str(char *str)
{
	char *dest;
	char *variable;
	int i;

	i = 0;
	dest = NULL;
	while (str[i])
	{
		add_until_dollard(&dest, str, &i);
		if (str[i] == '\0')
			return (dest);
		variable = extract_variable(str, &i);
		variable = expand_variable(variable);
		dest = ft_re_strjoin(dest, variable);
		ft_free(variable);
	}
	return (dest);
}

char *dquote_expand(char *to_expand, int *start)
{
	char *dest;
	int len;

	len = len_to_next_char(to_expand, *start, '"');
	dest = ft_substr(to_expand, *start + 1, len - 2);
	if (dest == NULL)
		return (NULL);
	*start += len;
	return (expand_str(dest));
}

char *quote_expand(char *str, int *start)
{
	char *dest;
	int len;

	len = len_to_next_char(str, *start, '\'');
	dest = ft_substr(str, *start + 1, len - 2);
	if (dest == NULL)
		return (NULL);
	*start += len;
	return (dest);
}

char *normal_expand(char *to_expand, int *start)
{
	char *dest;
	int len;

	len = 0;
	while (to_expand[*start + len] && to_expand[*start + len] != '"' && to_expand[*start + len] != '\'')
		len++;
	dest = ft_substr(to_expand, *start, len);
	if (dest == NULL)
		return (NULL);
	*start += len;
	return (expand_str(dest));
}


char **expand_word(char *word)
{
	char *result;
	char *dest;
	int start;
	char **tabb;

	start = 0;
	result = NULL;
	while (word[start])
	{
		if (word[start] == '"')
			dest = dquote_expand(word, &start);
		else if (word[start] == '\'')
			dest = quote_expand(word, &start);
		else
			dest = normal_expand(word, &start);
		result = ft_re_strjoin(result, dest);
	}
	tabb = ft_split(result, " \t");
	return tabb;
}

char **expand(char **args)
{
	char **dest;
	int i;

	i = 0;
	dest = NULL;
	if (args == NULL)
		return (NULL);
	while (args[i])
	{
		dest = re_str2djoin(dest, expand_word(args[i]));
		i++;
	}
	return (dest);
}
