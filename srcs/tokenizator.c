#include "../includes/minishell.h"

int check_cmd(char *line, int *index)
{
	int i;
	char *cmd[7];

	cmd[0] = "exit";
	cmd[1] = "pwd";
	cmd[2] = "echo";
	cmd[3] = "export";
	cmd[4] = "unset";
	cmd[5] = "env";
	cmd[6] = 0;
	i = 0;
	while (cmd[i])
	{
		if (ft_strncmp(line, cmd[i], ft_strlen(cmd[i])))
		{
			*index += ft_strlen(cmd[i]);
			return (1);
		}
		i++;
	}
	return (0);
}
int	calculate_tokens(char *line)
{
	int index;
	int num;

	index = 0;
	num = 0;
	while (line && line[index])
	{
		if (check_cmd(line + index, &index))
			num++;
		else
			index++;
	}
	return (num);
}

void	tokenizator(t_mini *shell)
{
//	int	token_num;

	parser(shell);
//	token_num = calculate_tokens(shell->processed_line);
//	printf("%d\n", token_num);
//	shell->tokens = token_split(shell);
}