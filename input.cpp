#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "input.hpp"

char *input_to_buffer( char *file_name, size_t *buffer_length )
{
    FILE *f = fopen(file_name, "r+b");
    struct stat stbuf;

    fstat(fileno(f), &stbuf);

    char *buffer = (char *)calloc(stbuf.st_size, sizeof(char));
    fread(buffer, sizeof(char), stbuf.st_size, f);

    fclose(f);

    *buffer_length = stbuf.st_size;

    return buffer;
}

void replace_slash_n( char *buffer, size_t buffer_length )
{
    for (int i = 0; i < buffer_length; i++)
    {
        if (*(buffer + i) == '\n')
            *(buffer + i) = '\0';
    }
}

int get_number_of_lines( char *buffer, size_t buffer_length )
{
    int number_of_lines = 0;

    for (size_t i = 0; i <= buffer_length; i++)
    {
        if (*(buffer + i) == '\0')
            number_of_lines++;
    }

    return number_of_lines;
}

void fill_struct_from_buffer( Line *line, int number_of_lines, char *buffer )
{
    for (int j = 0; j < number_of_lines; j++)
    {
        line[j].str = buffer;

        while (*buffer++ != '\0')
            ;

        buffer++;
    }
}
