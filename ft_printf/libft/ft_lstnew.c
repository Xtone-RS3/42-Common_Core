/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:22:29 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/13 14:22:31 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *data = strdup("Hello, linked list!");
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

	printf("Node content: %s\n", (char *)node->content);
	printf("Node next: %p\n", (void *)node->next);

	// Free allocated memory
	free(data);
	free(node);

	return 0;
}*/
