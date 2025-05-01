/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-01 10:02:32 by antabord          #+#    #+#             */
/*   Updated: 2025-05-01 10:02:32 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*atual;

	if (!new || !lst)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		atual = *lst;
		while (atual->next != NULL)
			atual = atual->next;
		atual->next = new;
	}
}

int	main(void)
{
	t_list *tail = ft_lstnew("adeus");
	t_list *n1 = ft_lstnew("tralalero");
	t_list *n2 = ft_lstnew("tralala");
	t_list *n3 = ft_lstnew("ola");

	ft_lstadd_back(&tail, n1);
	ft_lstadd_back(&tail, n2);
	ft_lstadd_back(&tail, n3);

	t_list *atual = tail;
	while (atual != NULL)
	{
		printf("conteudo nó: %s\n", (char *)atual->content);
		atual = atual->next;
	}
	free(n1);
	free(n2);
	free(n3);
	return (0);
}