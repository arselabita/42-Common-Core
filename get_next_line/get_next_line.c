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

static char    *line_to_return(char *leftovers)
{
    char    *printLine;
    int     i;
    int     j;

    i = 0;
    if (!leftovers)
        return (free (leftovers), NULL);
    while (leftovers[i] && leftovers[i] != '\n')
        i++;
    if (leftovers[i] == '\n')
        i++;
    printLine = (char *)ft_calloc(ft_strlen(leftovers) - i + 1 , sizeof(char));
    if (!printLine)
        return (NULL);
    j = 0;
    while (leftovers[i])
        printLine[j++] = leftovers[i++];
    printLine[j] = '\0';
    free (leftovers);
    return (printLine);
}

static char    *copy_next_line(char *leftovers)
{
    int     i;
    char    *copiedLine;

    i = 0;
    if (!leftovers)
        return (NULL);
    while (leftovers[i] && leftovers[i] != '\n')
        i++;
    copiedLine = (char *)ft_calloc(i + 2, sizeof(char)); // +2 sepse kemi 'n dhe \0
    if (!copiedLine)
        return (NULL);
    i = 0;
    while (leftovers[i] && leftovers[i] != '\n')
    {
        copiedLine[i] = leftovers[i];
        i++;
    }
    if (leftovers[i] == '\n')
        copiedLine[i++] = '\n';
    copiedLine[i] = '\0';
    return (copiedLine);
}
char    *get_next_line(int fd)
{
    char            *buffer; // a temporary storage area, to hold data nga read
    char            *nextLine; //Mban rreshtin që do të kthehet — ndërtohet nga leftover + buffer, deri te \n
    static char     *leftovers ; // tracks leftovers, nese un elexoj me shume ose me pak
    int             bytesToRead; // sa bajte janë lexuar 

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
    if (!buffer)
        return (NULL);
    bytesToRead = 1;
	while (!ft_strchr(leftovers, '\n') && bytesToRead > 0) // vazhdon derisa të kemi një \n ose fundin e fileit
    {
        bytesToRead = read(fd, buffer, BUFFER_SIZE);
        if (bytesToRead == -1)
           return (free(buffer), NULL);
        buffer[bytesToRead] = '\0';
        leftovers = ft_strjoin (leftovers, buffer); // nese nuk gjen \n vazhdo lexoje
    }
    free (buffer);
    if (!leftovers || leftovers[0] == '\0')
        return (free(leftovers), leftovers = NULL, NULL);
    nextLine = copy_next_line(leftovers);
    leftovers = line_to_return(leftovers);
    return (nextLine);
}

#include <stdio.h>

int main()
{
    int     fileDescriptor;
    char    *next_line;
    int     i;

    i = 0;
    fileDescriptor = open("get_next_line.txt", O_RDONLY); // Open the file on read and write mode
    if (fileDescriptor == -1)
    {
        printf("Error opening the file");
        return (1);
    }
    while (1)
    {
        next_line = get_next_line(fileDescriptor);
        if (next_line == NULL)
            break ;
        i++;
        printf("[%d]: %s\n", i, next_line);
        free (next_line);
        next_line = NULL;
    }
    close(fileDescriptor); // Close the file
    return (0);
}

