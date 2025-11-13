/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:31:52 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/14 14:31:53 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;

	if (!f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			while (first)
			{
				new = first->next;
				(*del)(first->content);
				free(first);
				first = new;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}

/*
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

// Helper to create a new node
t_list *ft_lstnew(void *content)
{
    t_list *node = malloc(sizeof(t_list));
    if (!node)
        return NULL;
    node->content = content;
    node->next = NULL;
    return node;
}

// Print list content assuming content is a string
void print_list(t_list *lst)
{
    while (lst)
    {
        printf("[%s] -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

// Function 'f' to apply: duplicate string and uppercase it
void *duplicate_upper(void *content)
{
    char *str = (char *)content;
    size_t len = ft_strlen(str);
    char *dup = malloc(len + 1);
    if (!dup)
        return NULL;
    for (size_t i = 0; i < len; i++)
        dup[i] = ft_toupper((unsigned char)str[i]);
    dup[len] = '\0';
    return dup;
}

// Function 'del' to free content
void del(void *content)
{
    printf("Freeing content: %s\n", (char *)content);
    free(content);
}

// Your ft_lstmap function prototype
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int main(void)
{
    // Create original list
    t_list *list = ft_lstnew(ft_strdup("apple"));
    list->next = ft_lstnew(ft_strdup("banana"));
    list->next->next = ft_lstnew(ft_strdup("cherry"));

    printf("Original list:\n");
    print_list(list);
    // Expected: [apple] -> [banana] -> [cherry] -> NULL

    // Create new mapped list using ft_lstmap
    t_list *new_list = ft_lstmap(list, duplicate_upper, del);

    printf("\nMapped list (all uppercase):\n");
    print_list(new_list);
    // Expected: [APPLE] -> [BANANA] -> [CHERRY] -> NULL

    // Cleanup
    ft_lstclear(&list, del);
    ft_lstclear(&new_list, del);

    return 0;
}*/