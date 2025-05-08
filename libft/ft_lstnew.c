/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:31:20 by abita             #+#    #+#             */
/*   Updated: 2025/05/06 12:31:26 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// Function to create a new node
t_list *ft_lstnew(void *content)
{
    struct s_list* newNode = (struct s_list*)malloc(sizeof(struct s_list));
    if (!newNode)
    {
        printf("Memory allocation failed.\n");
        return (NULL);
    }
    newNode->content = content;
    newNode->next = NULL;
    return (newNode);
}  


int main()
{
    struct s_list*  head = NULL;

    ft_lstnew(&head);
    printf("The new node is: ");
    return (0);
}
