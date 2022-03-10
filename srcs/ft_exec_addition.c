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

void	ft_cd(char **data_command)
{
	char	*buf;
	char	**cd_path;
	int		len_path;

	buf = ft_calloc(1, PATH_MAX);
	if (getcwd(buf, PATH_MAX) < 0 || !buf)
	{
		perror("getcwd");
		exit(1);
	}
	cd_path = ft_split(*data_command, '/');
	len_path = ft_strlen(buf) - 1;
	buf = ft_cd_add(cd_path, buf, len_path);
	free(cd_path);
	printf("%s\n", buf);
	printf("%d\n",chdir(buf));
//	if (chdir(buf) < 0)
//		perror("cd");
//	printf("%s/\n", buf);

	exit(0);
}

char	*ft_cd_add(char **cd_path, char *buf, int len_path)
{
	int	j;
	int	i;

	i = -1;
	while (cd_path[++i])
	{
		if (ft_strcmp(".", cd_path[i]))
			continue ;
		else if (ft_strcmp("..", cd_path[i]))
		{
			while (buf[len_path] != '/')
				buf[len_path--] = 0;
			if (len_path)
				buf[len_path--] = 0;
		}
		else
		{
			buf[++len_path] = '/';
			j = 0;
			while (cd_path[i][j])
				buf[++len_path] = cd_path[i][j++];
			buf[len_path + 1] = 0;
		}
	}
	return (buf);
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
