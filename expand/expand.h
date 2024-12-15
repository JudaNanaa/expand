/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 04:06:37 by madamou           #+#    #+#             */
/*   Updated: 2024/12/15 23:50:41 by madamou          ###   ########.fr       */
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
}t_env;

typedef struct s_data
{
	char **envp;
	int status;
	t_env *env;
}t_data;

char **expand(char **args);
int get_len_to_next_same_char(char *str, int i, char c);
t_data *get_data(void);

#endif