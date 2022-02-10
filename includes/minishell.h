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
	char				*name;
	char				*value;
	char				f_gl;
}	t_enviroment;

typedef struct s_data
{
	t_list				*env;
	int					argc;
	char				**argv;
	char				**envp;
	t_enviroment		*parsed_enviroment;
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
	struct s_cmd_token	*next;
}	t_cmd_token;

typedef struct s_glob_data
{
	int					exit_code;
	t_data				*data;
	int					process_mark;
	int					hd;
}	t_glob_data;

typedef struct s_complex_return
{
	int					exit_code;
	int					terminate;
	int					ext_code;
	char				*name;
}	t_complex_return;

extern t_glob_data			g_data;

int				get_path_count(char *str);
char			*get_path(char *str, int *start);
void			parse_enviroment(t_data *data);
void			enviroment_addback(t_enviroment **env, t_enviroment *new);
t_enviroment	*enviroment_addnew(int var_name_length, int value_length);
char			*get_environemt_value(char *name, t_data *data);
void			parse_path(t_data *data);
void			inition(t_data *data, int argc, char **argv, char **envp);
void			exit_err(char *str);
char			*get_enviroment_by_name(t_data *shell_data, char *str);
void			switch_echoctl(char on);
void			set_enviroment(t_data *shell_data,
					char *name_env, char *value_env, char f_gl);
char			*get_enviroment_name(char *str);
t_list			*list_element_finder(t_list *element, char *n_env);
t_enviroment	*ft_enviroment_addnew(int var_name_length, int value_length);
// char	*get_str_by_el(t_env *f);

#endif