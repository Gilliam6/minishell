/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expensive_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:45:09 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:45:10 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	copy_arg(t_mini *shell, char *new_line, int i, int *ind)
{
	int		len;
	int		index;
	t_env	*env;

	len = 0;
	while (shell->processed_line[i + len] && (shell->processed_line[i + len]
			!= ' ' && shell->processed_line[i + len] != '\"'))
		len++;
	index = len;
	env = compare_args(shell->processed_line + i, len, shell);
	if (!env)
		return (index);
	while (env->content[++len])
		new_line[(*ind)++] = env->content[len];
	return (index);
}

char	*construct_new_line(int mem_size, t_mini *shell)
{
	char	*new_line;
	int		i;
	int		index;

	new_line = (char *) save_malloc(mem_size, &shell->garbage);
	i = 0;
	index = 0;
	while (shell->processed_line[i])
	{
		if (shell->processed_line[i] == '$' && quotes(shell->processed_line,
				i) != 1)
			i += copy_arg(shell, new_line, i, &index);
		else
		{
			new_line[index] = shell->processed_line[i];
			i++;
			index++;
		}
	}
	new_line[index] = 0;
	return (new_line);
}
