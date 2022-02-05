#ifndef MINISHELL_H
# define MINISHELL_H

# define MSH_PROMPT "minishell$ "
# define MEM_ERR "Memory was allocated incorrectly\n"
# define PIPE_ERR "Pipe was init incorrectly\n"
# define FORK_ERR "Fork was run incorrectly\n"
# define HEREDOC "> "

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <termios.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <signal.h>
# include "../libft/libft.h"
// # include "../minishell.h"

typedef struct s_cmd_list
{
	struct s_cmd_token	*cmd_token;
	struct s_cmd_list	*next;
	int					logic_mark;
	int					piped;
}	t_cmd_list;

typedef struct s_env
{
	struct s_env		*next;
	char				*var_name;
	char				*value;
	char				f_gl;
}	t_env;

typedef struct s_data
{
	t_list				*env;
	int					argc;
	char			**argv;
	char				**envp;
	t_env				*env_parsed;
	char				**env_tosend;
	char				**path;
	int					last_exit_code;
}	t_data;

typedef struct s_cmd_token
{
	int					type;
	t_cmd_list			*cmd_list;
	t_list				*argv;
	t_list				*redirect_list;
	struct s_cmd_token			*next;
}	t_cmd_token;

typedef struct s_glob_data
{
	int					last_exit_code;
	t_data				*data;
	int					main_proc_mark;
	int					hd;
}	t_glob_data;

extern t_glob_data			g_data;

int		get_path_count(char *str);
char	*get_path(char *str, int *start);
void	ft_env_parse(t_data *data);
void	ft_env_addback(t_env **env, t_env *new);
t_env	*ft_env_addnew(int var_name_len, int value_len);
char	*get_var_value(char *var_name, t_data *data);
void	parse_path(t_data *data);
void	ft_init(t_data *data, int argc, char **argv, char **envp);
void	exit_err(char *str);
char	*get_env_by_name(t_data *sh_d, char *str);
void	switch_echoctl(char on);
void	set_env_by_name(t_data *sh_d, char *n_env, char *v_env, char f_gl);
char	*get_env_by_name(t_data *sh_d, char *str);
char	*get_env_name(char *str);
// char	*get_str_by_el(t_env *f);

#endif