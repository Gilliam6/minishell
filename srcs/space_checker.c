/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:26:29 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:26:30 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	calculate_strmem(char *str)
{
	int	mem_size;
	int	index;

	mem_size = 0;
	index = 0;
	while (str && str[index])
	{
		if (str[index] != ' ')
			mem_size++;
		else if (str[index] == ' ' && str[index + 1] == '-')
			mem_size++;
		else if (str[index] == ' ' && str[index + 1] != ' ')
			mem_size++;
		else if (str[index] == ' ' && quotes(str, index))
			mem_size++;
		index++;
	}
	return (mem_size);
}

char	*refactor_str(t_mini *shell, int mem_size, t_garbage **garbage)
{
	char	*final;
	int		index;

	final = (char *)save_malloc((sizeof(char) * mem_size) + 1, garbage);
	index = 0;
	mem_size = 0;
	while (shell->input_line && shell->input_line[index])
	{
		if (shell->input_line[index] != ' ')
			final[mem_size++] = shell->input_line[index];
		else if (shell->input_line[index] == ' ' && shell->input_line[index
				+ 1] == '-')
			final[mem_size++] = shell->input_line[index];
		else if (shell->input_line[index] == ' ' && shell->input_line[index
				+ 1] != ' ')
			final[mem_size++] = shell->input_line[index];
		else if (shell->input_line[index] == ' ' && quotes(shell->input_line,
				index))
			final[mem_size++] = shell->input_line[index];
		index++;
	}
	final[mem_size] = 0;
	return (final);
}

void	space_del(t_mini *shell)
{
	int	mem_size;

	mem_size = calculate_strmem(shell->input_line);
	shell->processed_line = refactor_str(shell, mem_size, &shell->garbage);
}
