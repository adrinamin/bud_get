#include <stdio.h>

int count_lines(FILE *file)
{
    int count = 0;
    char c;

    // Reset file pointer to the beginning of the file
    fseek(file, 0, SEEK_SET);

    // Count newline characters
    while ((c = fgetc(file)) != EOF)
    {
        if (c == '\n')
        {
            count++;
        }
    }

    // Reset file pointer to the beginning of the file again
    fseek(file, 0, SEEK_SET);

    return count;
}