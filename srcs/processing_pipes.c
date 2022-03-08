/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_pipes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:25:49 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:25:51 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**processing_pipes(t_mini *shell)
{
	char	**splitted;

	splitted = 0;
	if (shell->processed_line)
		splitted = ft_custom_split(shell->processed_line, '|', &shell->garbage);
	return (splitted);
}
