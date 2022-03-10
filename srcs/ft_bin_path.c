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

char	*ft_bin_path(t_garbage **garbage, t_env *env, char *command, char
*bin_path)
{
	char		**split_path;
	int			i;
	int			j;
	struct stat	f;

	split_path = ft_mega_custom_split(
			&env->content[ft_strlen(PATH) + 1], ':', garbage);
	while (*split_path)
	{
		i = 0;
		while (**split_path)
			bin_path[i++] = *(*split_path)++;
		bin_path[i++] = '/';
		j = 0;
		while (command[j])
			bin_path[i++] = command[j++];
		bin_path[i] = 0;
		if (lstat(bin_path, &f) == 0)
			return (bin_path);
		split_path++;
	}
	return (0);
}

char	*find_bin_path(char *command, t_env *env, t_garbage **garbage)
{
	char		*bin_path;

	bin_path = save_malloc(1024, garbage);
	while (env)
	{
		if (!ft_strncmp(env->content, PATH, ft_strlen(PATH)))
			return (ft_bin_path(garbage, env, command, bin_path));
		env = env->next;
	}
	return (0);
}
