/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_environment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:25:18 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:25:19 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	node_clear(t_env **lst)
{
	t_env	*tmp;

	while ((*lst))
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}

void	lst_add_back(t_env **env_chain, t_env *new)
{
	t_env	*checkpoint;

	if (!new)
		return ;
	if (*env_chain)
	{
		checkpoint = *env_chain;
		while ((*env_chain)->next)
			(*env_chain) = (*env_chain)->next;
		(*env_chain)->next = new;
		*env_chain = checkpoint;
	}
	else
		*env_chain = new;
}

t_env	*new_node(char *content, t_garbage **garbage)
{
	t_env	*new;

	new = (t_env *)save_malloc(sizeof(t_env), garbage);
	new->content = content;
	new->next = 0;
	return (new);
}

t_env	*init_environment(char **env, t_garbage **garbage)
{
	t_env	*envi;
	t_env	*new;
	int		i;

	envi = new_node(env[0], garbage);
	i = 1;
	while (env[i])
	{
		new = new_node(env[i], garbage);
		lst_add_back(&envi, new);
		i++;
	}
	return (envi);
}
