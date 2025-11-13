/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:01:03 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/14 12:01:04 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del)
		return ;
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}

/*
void del(void *content)
{
    printf("Deleting content: %s\n", (char *)content);
    free(content);
}

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
        printf("[%s] -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

int main(void)
{
    t_list *node1 = ft_lstnew(ft_strdup("Node 1"));
    t_list *node2 = ft_lstnew(ft_strdup("Node 2"));
    t_list *node3 = ft_lstnew(ft_strdup("Node 3"));

    node1->next = node2;
    node2->next = node3;

    printf("Original list:\n");
    print_list(node1);
    // Expected: [Node 1] -> [Node 2] -> [Node 3] -> NULL

    // Delete node2 using ft_lstdelone (you implement this)
    printf("\nCalling ft_lstdelone on node2:\n");
    ft_lstdelone(node2, del);  // <-- you write this function

    printf("\nList after deleting node2 (pointer still in node1->next):\n");
    print_list(node1);

    // Optional: manually fix the broken link for demonstration
    node1->next = node3;

    printf("\nList after fixing node1->next to skip deleted node2:\n");
    print_list(node1);
    // Expected: [Node 1] -> [Node 3] -> NULL

    // Clean up remaining nodes
    ft_lstdelone(node1, del);
    ft_lstdelone(node3, del);

    return 0;
}*/
