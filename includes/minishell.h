#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>

typedef struct env_list
{
	char			*content;
	struct env_list	*next;
}				t_env;

t_env	*init_environment(char **env);
#endif