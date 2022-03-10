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

void	ft_execve(char **command, t_env *env, t_garbage **garbage)
{
	char	**env_array;
	char	*bin_path;

	env_array = env_convert(env, garbage);
	bin_path = find_bin_path(command[0], env, garbage);
	if (!bin_path)
		exit(1);
	if (execve(bin_path, command, env_array) < 0)
	{
		perror("execve");
		exit (1);
	}
	exit (0);
}

void	ft_do_cmd(char **command, t_env **env, t_garbage **garbage)
{
	if (ft_strcmp(command[0], STR_ECHO))
		ft_echo(++command);
	else if (ft_strcmp(command[0], STR_CD))
		ft_cd(++command);
	else if (ft_strcmp(command[0], STR_PWD))
		ft_pwd();
	else if (ft_strcmp(command[0], STR_EXPORT))
		ft_export(++command, env, garbage);
	else if (ft_strcmp(command[0], STR_UNSET))
		ft_unset(++command, env);
	else if (ft_strcmp(command[0], STR_ENV))
		ft_env(*env);
	else
		ft_execve(command, *env, garbage);
}

void	check_pipe(int *fd)
{
	if (pipe(fd) < 0)
	{
		perror("pipe");
		return ;
	}
}

void	ft_exec_command(t_mini *shell)
{
	t_tok	*token;
	int		fd[2];
	pid_t	pid;

	token = shell->tokens;
	while (token)
	{
		if (token->next)
		{
			check_pipe(fd);
			token->std[1] = fd[1];
			token->next->std[0] = fd[0];
		}
		pid = fork();
		if (pid == -1)
			perror("fork");
		else if (pid == 0)
		{
			file_descriptor_handler(token->std[0], token->std[1]);
			ft_do_cmd(token->name, &shell->envi, &shell->garbage);
		}
		else
			waitpid(pid, 0, WUNTRACED);
		token = token->next;
	}
}
