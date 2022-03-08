/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:25:25 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:25:27 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	unexpected_exit(t_garbage **garbage, char *str, int ret)
{
	if (*garbage)
		ft_custom_lstclear(garbage, free);
	if (str)
		ft_putstr_fd(str, 1);
	exit(ret);
}

int	ft_strerror(char *str, int ret)
{
	ft_putstr_fd(str, 1);
	return (ret);
}

void	switch_echoctl(char on)
{
	struct termios	ts;

	tcgetattr(STDIN_FILENO, &ts);
	if (on)
		ts.c_lflag |= ECHOCTL;
	else
		ts.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &ts);
}

int	main(void)
{
	t_mini		shell;
	extern char	**environ;

	ft_memset(&shell, 0, sizeof(t_mini));
	shell.envi = init_environment(environ, &shell.garbage);
	switch_echoctl(0);
	while (!shell.exit)
	{
		set_input_signals();
		shell.input_line = readline("minishell$");
		signal(SIGINT, &signal_handler);
		signal(SIGQUIT, SIG_IGN);
		if (!shell.input_line || ft_strcmp("exit", shell.input_line))
		{
			ft_putstr_fd("\033[11C", 1);
			ft_putstr_fd("\x1bM\x1b[`exit\n", 1);
			break ;
		}
		tokenizator(&shell);
		ft_exec_command(&shell);
		add_history(shell.input_line);
	}
	ft_custom_lstclear(&shell.garbage, free);
	printf("%s\n", "🖕");
	return (0);
}
