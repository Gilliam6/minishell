/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:46:33 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:46:47 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
	if (chdir(buf) < 0)
		perror("cd");
	exit (0);
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
		}
	}
	return (buf);
}
