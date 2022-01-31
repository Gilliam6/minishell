#include "../includes/minishell.h"

int	tokens_size(t_tok *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

//void	ft_custom_lstclear(t_garbage **lst, void (*del)(void*))
//{
//	t_garbage	*tmp;
//
//	while ((*lst))
//	{
//		tmp = (*lst)->next;
//		(*del)((*lst)->content);
//		free(*lst);
//		*lst = tmp;
//	}
//}

void	token_add_back(t_tok **lst, t_tok *new)
{
	t_tok	*begin;

	if (!new)
		return ;
	if (*lst)
	{
		begin = *lst;
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = new;
		*lst = begin;
	}
	else
		*lst = new;
}

t_tok	*create_new_token(int index, char *str, t_garbage **garbage)
{
	t_tok	*elem;

	elem = save_malloc(sizeof(t_tok), garbage);
	if (!elem)
		return (0);
	elem->name = str;
	elem->index = index;
	elem->next = 0;
	return (elem);
}

void	token_add(t_tok **tokens, t_garbage **garbage, int index, char *str)
{
	t_tok	*new;

	new = create_new_token(index, str, garbage);
	token_add_back(tokens, new);
//	return (pointer);
}