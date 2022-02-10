#include "../includes/minishell.h"

static char	*get_string_by_element(t_env *enviroment)
{
	char	*result;
	int		length;

	if (enviroment)
	{
		length = ft_strlen(enviroment->value);
		result = malloc(sizeof(char) * (length + 1));
		if (!result)
			exit_err(MLC_ERR);
		result[length] = 0;
		ft_memcpy(result, enviroment->value, length);
	}
	else
	{
		result = malloc(sizeof(char));
		if (!result)
			exit_err(MLC_ERR);
		result[0] = 0;
	}
	return (result);
}

char	*get_environment_by_name(t_mini *shell_data, char *str)
{
	t_env	*environment_element;
	t_env	*new_environment_element;

	new_environment_element = NULL;
	if (shell_data->envi)
	{
		environment_element = shell_data->envi;
		while (environment_element)
		{
			if (!ft_strncmp(str, environment_element->name, ft_strlen(str) + 1))
			{
				new_environment_element = environment_element;
				break ;
			}
			environment_element = environment_element->next;
		}
	}
	return (get_string_by_element(new_environment_element));
}

t_list	*list_element_finder(t_list *element, char *name_env)
{
	t_env	*element_content;

	while (element)
	{
		element_content = (t_env *)element->content;
		if (!ft_strncmp(name_env,
				element_content->name, ft_strlen(name_env) + 1))
			break ;
		element = element->next;
	}
	return (element);
}

t_list	*ft_lsstlast(t_list *lst)
{
	t_list	*l;

	l = lst;
	if (l != NULL)
	{
		while ((*l).next != NULL)
			l = (*l).next;
		return (l);
	}
	return (NULL);
}

void	ft_lsstadd_back(t_list **lst, t_list *new)
{	
	t_list	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lsstlast(*lst);
	(*last).next = new;
}

t_list	*ft_lsstnew(void *content)
{
	t_list	*begin;

	begin = (t_list *)malloc(sizeof(*begin));
	if (!begin)
		return (NULL);
	(*begin).content = content;
	(*begin).next = NULL;
	return (begin);
}