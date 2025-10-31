/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:52:33 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/31 11:58:25 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}

/*
t_list	*ft_lstnew(void *content)
{
	t_list *node;
	
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

int main(void)
{
	char *data = ft_strdup("Hello, linked list!");
	if (!data)
	{
		perror("strdup");
		return 1;
	}

	t_list *node = ft_lstnew(data);
	if (!node)
	{
		perror("ft_lstnew");
		free(data);
		return 1;
	}
	char *data2 = ft_strdup("lol");
	if (!data2)
	{
		perror("strdup");
		return 1;
	}
	t_list *node2 = ft_lstnew(data2);
	if (!node2)
	{
		perror("ft_lstnew");
		free(data2);
		return 1;
	}
	ft_lstadd_front(&node,node2);
	printf("%s\n",node->content);
	printf("%s\n",node->next->content);
}*/
