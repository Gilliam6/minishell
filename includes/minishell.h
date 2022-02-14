#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

//MSG
# define MLC_ERR	"Malloc failed\n"
# define QUOT_ERR	"Minishell syntax error: open quotes\n"

//CMD
# define EXIT			1
# define ECHO			2
# define PWD			3
# define EXPORT			4
# define UNSET			5
# define ENV			6

//OP(operators)
# define PIPE			7
# define RD_INPUT		8
# define RD_OUTPUT		9
# define RD_OUTPUT_X2	10

//BUILTINS
#define PATH_MAX        1024
#define STR_ECHO        "echo"
#define STR_CD          "cd"
#define STR_PWD         "pwd"
#define STR_EXPORT      "export"
#define STR_UNSET       "unset"
#define STR_ENV         "env"
#define STR_EXIT        "exit"


# define MAX_INT		2147483647

typedef struct	pointers
{
	void				*content;
	struct pointers		*next;
}				t_garbage;

typedef struct env_list
{
	char			*content;
	struct env_list	*next;
}				t_env;

//typedef struct commands_line
//{
//	unsigned char			type;
//	char 					*text;
//	struct commands_line	*next;
//}				t_cmd;

typedef struct tokens_list
{
	char				**name;
//	t_cmd 				cmd;
	struct tokens_list	*next;
}			t_tok;

typedef struct s_minishell
{
	char			*input_line;
	char 			*processed_line;
	unsigned char	exit;
	unsigned char 	stop;
	t_env			*envi;
	t_tok			*tokens;
	t_garbage		*garbage;
}			t_mini;

// Main
t_env		*init_environment(char **env, t_garbage **garbage);
int 		ft_strerror(char *str, int ret);
int			unexpected_exit(t_garbage **garbage, char *str, int ret);


// Malloc abstract || garbage collector
int			ft_custom_lstsize(t_garbage *lst); // check size of link
void		ft_custom_lstclear(t_garbage **lst, void (*del)(void*));
void		ft_custom_lstadd_front(t_garbage **lst, t_garbage *new);
t_garbage	*ft_custom_lstnew(void *content);
void		*save_malloc(int num_bytes, t_garbage **garbage);

// Parser
void		tokenizator(t_mini *shell);
char		**parser(t_mini *shell);
int 		quotes(char *line, int i); // Quotes checker
int 		quot_checker(char *line, int i);
char		**ft_custom_split(char const *s, char c, t_garbage **garbage);
void		space_del(t_mini *shell);
char		**processing_pipes(t_mini *shell);
void		processing_dollars(t_mini *shell);


// Tokens creator
void		token_add(t_tok **tokens, t_garbage **garbage, char **str);
int			tokens_size(t_tok *lst);
void		print_tokens(t_tok *tokens);

// Exec command
void        ft_exec_command(t_mini *shell);




#endif