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
#include <stdio.h>

char    *get_next_line(int fd)
{
    static char buffer[290];
    char    *next_line;
    int buffer_len;
    int i;

    if (fd == -1)
    {
        printf("\nError Opening FIle!!\n");
        return (-1);
    }
    buffer_len = ft_strlen(buffer);
    next_line = (char *)ft_calloc(buffer_len + 1, sizeof(char));
    if (!next_line)
        return (NULL);
    read(fd, next_line, sizeof(next_line)); // Read 290 bytes
    i = 0;
    while (next_line[i])
    {
        if (next_line[i] == '\n')
        {

        }
        i++;
    }
    return (free(next_line), next_line);
}
int main()
{
    int fileDescriptor;
    char    *fileName;
    char    *result;

    fileName = "get_next_line.txt";
    fileDescriptor = open(fileName, O_RDWR); // Open the file on read and write mode
    result = get_next_line(fileDescriptor);

    close(fileDescriptor); // Close the file
    printf("Connects of the file %s\n", fileName);
    printf("Connects of the file %s\n", fileDescriptor);
    printf("Connects of the file %s\n", result);
    return (0);
}