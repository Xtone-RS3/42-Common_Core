/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:08:21 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/14 11:08:22 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}

/*
t_list *ft_lstnew(void *content)
{
	t_list *node = malloc(sizeof(t_list));
	if (!node)
		return NULL;
	node->content = content;
	node->next = NULL;
	return node;
}

void print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

int main(void)
{
	t_list *list = NULL;

	// Adding first node
	t_list *node1 = ft_lstnew("Node 1");
	ft_lstadd_back(&list, node1);
	printf("After adding node1:\n");
	print_list(list);
	// Expected: Node 1 -> NULL

	// Adding second node
	t_list *node2 = ft_lstnew("Node 2");
	ft_lstadd_back(&list, node2);
	printf("After adding node2:\n");
	print_list(list);
	// Expected: Node 1 -> Node 2 -> NULL

	// Adding third node
	t_list *node3 = ft_lstnew("Node 3");
	ft_lstadd_back(&list, node3);
	printf("After adding node3:\n");
	print_list(list);
	// Expected: Node 1 -> Node 2 -> Node 3 -> NULL

	return 0;
}*/