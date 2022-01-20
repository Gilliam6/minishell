#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*begin;

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
