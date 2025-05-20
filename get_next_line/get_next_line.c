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

/*This project is about programming a function that returns a line
read from a file descriptor.

File Descriptors are simply non-negative integers that act as handles
for these files or resources. They serve as communication channel between the user-space
applications and the kernel-space system calls for I/O operations.

There is a limit to file descriptors, mainly two reasons:
    1. Resource Managements: Too many open files can hog system resources
    2. Security: To prevent any form of denial-of-service attacks.

Basically unique identifiers that help the system manage your interactions
with various things.

If i want to read smth from a file named get_next_line.txt, the steps would be:access
    1. Open the file: You get a File Descriptor lets say fd = 3
    2. Read or Write: Use fd to read/write
    3. Close: Finally close the file
*/

#include "get_next_line.h"

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
    while (!ft_strchr(helper, '\n') && bytesToRead != 0) // if not \n and not empty
    {
        bytesToRead = read(fd, nextLine, BUFFER_SIZE); // continue reading
        if (bytesToRead == -1)
           return (free (buffer), NULL);
        nextLine[bytesToRead] = '\0';
        helper = ft_strjoin(helper, buffer);
    }
    free (buffer);
    return (nextLine);
}
