/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_addition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:55:27 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:55:29 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_echo(char **data_command)
{
	char	flag_n;
	char	flag_space;

	flag_n = 0;
	flag_space = 0;
	while (*data_command)
	{
		if (ft_strcmp(*data_command, "-n"))
			flag_n = 1;
		else
		{
			if (flag_space)
				printf(" ");
			printf("%s", *data_command);
			flag_space = 1;
		}
		data_command++;
	}
	if (!flag_n)
		printf("\n");
	exit(0);
}

void	ft_pwd(void)
{
	char	buf[PATH_MAX];

	if (getcwd(buf, PATH_MAX) < 0)
		perror("getcwd");
	else
		printf("%s\n", buf);
	exit(0);
}

void	ft_export(char **data_command, t_env **env, t_garbage **garbage)
{
	t_env	*begin;

	begin = *env;
	if (!begin)
	{
		*env = new_node(*data_command, garbage);
		return ;
	}
	while (begin->next)
		begin = begin->next;
	begin->next = new_node(*data_command, garbage);
	exit(0);
}

void	ft_unset(char **data_command, t_env **env)
{
	t_env	*begin;
	t_env	*prev;

	begin = *env;
	prev = 0;
	while (begin)
	{
		if (ft_strcmp(begin->content, *data_command))
		{
			if (prev)
			{
				prev->next = begin->next;
				free(begin->content);
				free(begin);
			}
			else
				*env = (*env)->next;
			break ;
		}
		prev = begin;
		begin = begin->next;
	}
	exit(0);
}
