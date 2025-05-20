/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:56:33 by abita             #+#    #+#             */
/*   Updated: 2025/05/17 13:56:38 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_next_line_helper(char *helper)
{
    int i;

    i = 0;
    while (helper[i] && helper[i] != '\n')
        i++;
    if (helper[i] == '\n')
        i++;
    
    return (helper);
}

char    *get_next_line(int fd)
{
    char            *nextLine;
    char            *buffer;
    static char     *helper;
    int             bytesToRead;

    if (fd == -1 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
    if (!buffer)
        return (NULL);
    bytesToRead = 1;
    while (!ft_strchr(helper, '\n') && bytesToRead != 0) // vazhdon derisa të kemi një \n ose fundin e fileit
    {
        bytesToRead = read(fd, buffer, BUFFER_SIZE); // continue reading
        if (bytesToRead == -1)
           return (free (buffer), NULL);
        buffer[bytesToRead] = '\0';
        helper = ft_strjoin(helper, buffer); // bashkojmë leximin e ri me çfarë kemi mbledhur
    }
    free (buffer);
    nextLine = ft_next_line_helper(helper);
    return (nextLine);
}
