/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:03:18 by marvin            #+#    #+#             */
/*   Updated: 2025/05/02 17:03:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    addlst(t_list *newlst, t_list *node)
{
    t_list *atual;

    atual = newlst;
    while (atual != NULL)
    {
        newlst->next = node;
        atual = atual->next;
    }
}

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    
}

void ft_uppercase(void *content)
{
	char *c;

	c = (char *)content;
	while (*c)
	{
		if (*c >= 'a' && *c <= 'z')
			*c = *c - 32;
		c++;
	}
}

int main(void)
{
    t_list *tmp;
    t_list *n1 = ft_lstnew(strdup("ola"));
    t_list *n2 = ft_lstnew(strdup("tudo"));
    t_list *n3 = ft_lstnew(strdup("bem"));

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    tmp = n1;
    printf("antes da funçao:\n");
    while (tmp != NULL)
    {
        printf("%s\n", (char *)tmp->content);
        tmp = tmp->next;
    }
    tmp = NULL;
    tmp = n1;
    ft_lstmap(n1, ft_uppercase, del);
    printf("depois:\n");
    while (tmp != NULL)
    {
        printf("%s\n", (char *)tmp->content);
        tmp = tmp->next;
    }
    tmp = NULL;
    free(n1);
    free(n2);
    free(n3);
    return (0);

}