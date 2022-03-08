/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_dollars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:25:41 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:25:42 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*compare_args(char *str, int len, t_mini *shell)
{
	t_env	*env;

	env = shell->envi;
	while (env)
	{
		if (!ft_strncmp(str + 1, env->content, len - 1))
			break ;
		env = env->next;
	}
	return (env);
}

int	count_arg_size(char *str)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i] != '=')
		i++;
	while (str[i] && str[i] != ' ')
	{
		len++;
		i++;
	}
	return (len);
}

int	arg_size(t_env *env)
{
	int	len;

	len = 0;
	if (env)
		len = count_arg_size(env->content);
	return (len);
}

int	calculate_new_line(char *str, int i, t_mini *shell)
{
	int		len;
	t_env	*env;

	len = 0;
	while (str[i + len] && (str[i + len] != ' ' && str[i + len] != '\"'))
		len++;
	env = compare_args(str + i, len, shell);
	len = arg_size(env) - len;
	return (len);
}

void	processing_dollars(t_mini *shell)
{
	int		index;
	int		mem_size;
	char	*new_line;

	index = 0;
	mem_size = 0;
	while (shell->processed_line && shell->processed_line[index])
	{
		if (shell->processed_line[index] == '$' && quotes
			(shell->processed_line, index) != 1)
			mem_size += calculate_new_line(shell->processed_line, index, shell);
		index++;
	}
	mem_size = ft_strlen(shell->processed_line) + mem_size + 1;
	new_line = construct_new_line(mem_size, shell);
	shell->processed_line = new_line;
}
