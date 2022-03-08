/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:25:32 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:25:34 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**parser(t_mini *shell)
{
	char	**split;

	if (quot_checker(shell->input_line, MAX_INT))
		return (0);
	space_del(shell);
	processing_dollars(shell);
	split = processing_pipes(shell);
	return (split);
}
