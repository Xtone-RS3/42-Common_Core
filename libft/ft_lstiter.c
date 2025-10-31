/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:24:35 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/31 11:58:17 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*node;

	node = lst;
	if (!node)
		return ;
	while (node)
	{
		(*f)(node->content);
		node = node->next;
	}
}

/*
void to_upper(void *content)
{
    char *str = (char *)content;
    for (int i = 0; str[i]; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
}

void print_content(void *content)
{
    printf("Visiting: %s\n", (char *)content);
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

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*node2;

	node = *lst;
	node2 = *lst;
	while (node != NULL)
	{
		node2 = node->next;
		del(node->content);
		free(node);
		node = node2;
	}
	*lst = NULL;
}

int main(void)
{
    // Create list with strdup'd strings so we can modify them
    t_list *list = ft_lstnew(ft_strdup("first"));
    list->next = ft_lstnew(ft_strdup("second"));
    list->next->next = ft_lstnew(ft_strdup("third"));

    printf("Original list:\n");
    print_list(list);
    // Expected: [first] -> [second] -> [third] -> NULL

    // Apply ft_lstiter with print_content
    printf("\nCalling ft_lstiter with print_content:\n");
    ft_lstiter(list, print_content);
    // Expected:
    // Visiting: first
    // Visiting: second
    // Visiting: third

    // Apply ft_lstiter with to_upper
    printf("\nCalling ft_lstiter with to_upper:\n");
    ft_lstiter(list, to_upper);

    // Print list again to verify change
    printf("\nList after to_upper:\n");
    print_list(list);
    // Expected: [FIRST] -> [SECOND] -> [THIRD] -> NULL

    // Clean up
    ft_lstclear(&list, free);  // You should have this by now

    return 0;
}*/
