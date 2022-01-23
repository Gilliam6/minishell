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
# define RD_INPUT_X2	10
# define RD_OUTPUT_X2	11

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

typedef struct tokens_list
{
	char				*name;
	unsigned char 		type;
	struct tokens_list	*next;
	struct tokens_list	*back;
}			t_tok;

typedef struct s_minishell
{
	char			*input_line;
	unsigned char	exit;
	t_env			*envi;
	t_tok			*tokens;
	t_garbage		*garbage;
}			t_mini;

// Main
t_env	*init_environment(char **env, t_garbage **garbage);
int ft_strerror(char *str);


// Malloc abstract || garbage collector
int			ft_custom_lstsize(t_garbage *lst); // check size of link
void		ft_custom_lstclear(t_garbage **lst, void (*del)(void*));
void		ft_custom_lstadd_front(t_garbage **lst, t_garbage *new);
t_garbage	*ft_custom_lstnew(void *content);
void		*save_malloc(int num_bytes, t_garbage **garbage);

// Parser
void	tokenizator(t_mini *shell);
char 	**parser(t_mini *shell);




#endif