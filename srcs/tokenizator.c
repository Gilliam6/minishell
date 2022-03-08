/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:24:35 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:24:46 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	token_constructor(char **split, t_mini *shell)
{
	int		i;
	char	**tmp;

	i = 0;
	while (split[i])
	{
		tmp = ft_mega_custom_split(split[i], ' ', &shell->garbage);
		token_add(&shell->tokens, &shell->garbage, tmp);
		i++;
	}
}

void	tokenizator(t_mini *shell)
{
	char	**split;

	shell->tokens = 0;
	split = parser(shell);
	if (split)
		token_constructor(split, shell);
	redirect_deleter(shell);
}
