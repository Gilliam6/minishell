/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_opt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:55:41 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:55:46 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_env(t_env *env)
{
	while (env)
	{
		printf("%s\n", env->content);
		env = env->next;
	}
	exit (0);
}

int	len_list_env(t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		env = env->next;
		i++;
	}
	return (i);
}

char	**env_convert(t_env *env, t_garbage **garbage)
{
	int		len;
	int		i;
	char	**result_env;

	len = len_list_env(env);
	result_env = (char **)save_malloc(sizeof(char *) * (len + 1), garbage);
	result_env[len] = 0;
	i = 0;
	while (env)
	{
		result_env[i] = env->content;
		env = env->next;
		i++;
	}
	return (result_env);
}
