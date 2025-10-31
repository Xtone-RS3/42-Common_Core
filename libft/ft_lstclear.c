/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:10:12 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/31 11:58:22 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
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
    t_list *list = NULL;

    // Create list with 3 dynamically allocated contents
    list = ft_lstnew(ft_strdup("One"));
    list->next = ft_lstnew(ft_strdup("Two"));
    list->next->next = ft_lstnew(ft_strdup("Three"));

    printf("Initial list:\n");
    print_list(list);
    // Expected: [One] -> [Two] -> [Three] -> NULL

    printf("\nCalling ft_lstclear:\n");
    ft_lstclear(&list, del);  // <--- You implement this

    // After clear, list should be NULL
    if (list == NULL)
        printf("\nList has been cleared successfully and is now NULL \n");
    else
        printf("\nList is NOT NULL \n");

    return 0;
}*/