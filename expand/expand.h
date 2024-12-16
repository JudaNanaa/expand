/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 04:06:37 by madamou           #+#    #+#             */
/*   Updated: 2024/12/16 02:49:40 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
#define EXPAND_H

# include "../libft/libft.h"
# include "../garbage_collector/garbage.h"

typedef struct s_env
{
	char *key;
	char *value;
	struct s_env *next;
	struct s_env *prev;
}t_env;

typedef struct s_data
{
	char **envp;
	int status;
	t_env *env;
}t_data;

char **expand(char **args);
int len_to_next_char(char *str, int i, char c);
t_data *get_data(void);
t_env	*env_in_struct(char **envp);

#endif