#include "minishell.h"

t_enviroment	*enviroment_addnew(int var_name_length, int value_length)
{
	t_enviroment	*new;

	new = (t_enviroment *)malloc(sizeof(t_enviroment));
	if (!new)
		exit(1);
	new->value = (char *)malloc((value_length + 1) * sizeof(char));
	new->name = (char *)malloc((var_name_length + 1) * sizeof(char));
	if (!new->value || !new->name)
		exit(1);
	new->next = NULL;
	return (new);
}

static char	*get_string_by_element(t_enviroment *enviroment)
{
	char	*result;
	int		length;

	if (enviroment)
	{
		length = ft_strlen(enviroment->value);
		result = malloc(sizeof(char) * (length + 1));
		if (!result)
			exit_err(MEM_ERR);
		result[length] = 0;
		ft_memcpy(result, enviroment->value, length);
	}
	else
	{
		result = malloc(sizeof(char));
		if (!result)
			exit_err(MEM_ERR);
		result[0] = 0;
	}
	return (result);
}

char	*get_enviroment_by_name(t_data *shell_data, char *str)
{
	t_enviroment	*enviroment_element;
	t_enviroment	*new_enviroment_element;

	new_enviroment_element = NULL;
	if (shell_data->parsed_enviroment)
	{
		enviroment_element = shell_data->parsed_enviroment;
		while (enviroment_element)
		{
			if (!ft_strncmp(str, enviroment_element->name, ft_strlen(str) + 1))
			{
				new_enviroment_element = enviroment_element;
				break ;
			}
			enviroment_element = enviroment_element->next;
		}
	}
	return (get_string_by_element(new_enviroment_element));
}

t_list	*list_element_finder(t_list *element, char *name_env)
{
	t_enviroment	*element_content;

	while (element)
	{
		element_content = (t_enviroment *)element->content;
		if (!ft_strncmp(name_env,
				element_content->name, ft_strlen(name_env) + 1))
			break ;
		element = element->next;
	}
	return (element);
}

void	set_enviroment(t_data *shell_data,
			char *name_env, char *value_env, char f_gl)
{
	t_list			*element;
	t_enviroment	*element_content;

	element = list_element_finder(shell_data->env, name_env);
	if (element)
	{
		element_content = (t_enviroment *)element->content;
		if (element_content->value)
			free(element_content->value);
		element_content->value = value_env;
		if (f_gl > element_content->f_gl)
			element_content->f_gl = f_gl;
		free(name_env);
	}
	else
	{
		element_content = malloc(sizeof(t_enviroment));
		if (!element_content)
			exit_err(MEM_ERR);
		element_content->name = name_env;
		element_content->value = value_env;
		element_content->f_gl = f_gl;
		ft_lstadd_back(&(shell_data->env), ft_lstnew(element_content));
	}
}
