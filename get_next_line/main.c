#include "get_next_line.h"
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