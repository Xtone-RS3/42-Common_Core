/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:57:49 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/31 11:58:07 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*node;
	int		i;

	i = 0;
	node = lst;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
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

    int size = ft_lstsize(head);
    printf("List size: %d\n", size);

    // Free memory (good practice)
    t_list *temp;
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}*/