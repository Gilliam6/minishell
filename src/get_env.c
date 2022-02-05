#include "minishell.h"

t_env	*ft_env_addnew(int var_name_len, int value_len)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		exit(1);
	new->value = (char *)malloc((value_len + 1) * sizeof(char));
	new->var_name = (char *)malloc((var_name_len + 1) * sizeof(char));
	if (!new->value || !new->var_name)
		exit(1);
	new->next = NULL;
	return (new);
}

static char	*get_str_by_el(t_env *f)
{
	char	*res;
	int		l;

	if (f)
	{
		l = ft_strlen(f->value);
		res = malloc(sizeof(char) * (l + 1));
		if (!res)
			exit_err(MEM_ERR);
		res[l] = 0;
		ft_memcpy(res, f->value, l);
	}
	else
	{
		res = malloc(sizeof(char));
		if (!res)
			exit_err(MEM_ERR);
		res[0] = 0;
	}
	return (res);
}

char	*get_env_by_name(t_data *sh_d, char *str)
{
	t_env	*el_env;
	t_env	*f_el_env;

	f_el_env = NULL;
	if (sh_d->env_parsed)
	{
		el_env = sh_d->env_parsed;
		while (el_env)
		{
			if (!ft_strncmp(str, el_env->var_name, ft_strlen(str) + 1))
			{
				f_el_env = el_env;
				break ;
			}
			el_env = el_env->next;
		}
	}
	return (get_str_by_el(f_el_env));
}

t_list	*lst_el_found(t_list *f_el, char *n_env)
{
	t_env	*el_con;

	while (f_el)
	{
		el_con = (t_env *)f_el->content;
		if (!ft_strncmp(n_env, el_con->var_name, ft_strlen(n_env) + 1))
			break ;
		f_el = f_el->next;
	}
	return (f_el);
}

void	set_env_by_name(t_data *sh_d, char *n_env, char *v_env, char f_gl)
{
	t_list	*f_el;
	t_env	*el_con;

	f_el = lst_el_found(sh_d->env, n_env);
	if (f_el)
	{
		el_con = (t_env *)f_el->content;
		if (el_con->value)
			free(el_con->value);
		el_con->value = v_env;
		if (f_gl > el_con->f_gl)
			el_con->f_gl = f_gl;
		free(n_env);
	}
	else
	{
		el_con = malloc(sizeof(t_env));
		if (!el_con)
			exit_err(MEM_ERR);
		el_con->var_name = n_env;
		el_con->value = v_env;
		el_con->f_gl = f_gl;
		ft_lstadd_back(&(sh_d->env), ft_lstnew(el_con));
	}
}

