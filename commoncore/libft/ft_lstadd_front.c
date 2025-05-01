/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-01 08:50:57 by antabord          #+#    #+#             */
/*   Updated: 2025-05-01 08:50:57 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

/*int	main(void)
{
	t_list *head = ft_lstnew("ola");
	t_list *n2 = ft_lstnew("tralalero");
	t_list *n3 = ft_lstnew("tralala");

	ft_lstadd_front(&head, n2);
	ft_lstadd_front(&head, n3);

	t_list *atual = head;
	while (atual != NULL)
	{
		printf("conteudo nó: %s\n", (char *)atual->content);
		atual = atual->next;
	}
	free(n2);
	free(n3);
	return (0);
}*/