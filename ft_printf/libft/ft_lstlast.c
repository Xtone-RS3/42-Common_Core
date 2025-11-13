/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:03:27 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/14 11:03:28 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	node = lst;
	while (node)
	{
		if (!node->next)
			return (node);
		node = node->next;
	}
	return (node);
}

/*
t_list *new_node(void *content)
{
    t_list *node = (t_list *)malloc(sizeof(t_list));
    if (!node)
        return NULL;
    node->content = content;
    node->next = NULL;
    return node;
}

int main(void)
{
    t_list *head = new_node("Node 1");
    head->next = new_node("Node 2");
    head->next->next = new_node("Node 3");

    t_list *last = ft_lstlast(head);
    if (last)
        printf("Last node content: %s\n", (char *)last->content);
    else
        printf("List is empty.\n");

    // Free memory
    t_list *temp;
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}*/
