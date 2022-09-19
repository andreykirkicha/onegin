#ifndef INPUT_HPP
#define INPUT_HPP

#include <stdio.h>

struct Line
{
    char *str;
    int str_length;
};

char *input_to_buffer( char *FileName, size_t *buffer_length );
void replace_slash_n( char *buffer, size_t buffer_length );
int get_number_of_lines( char *buffer, size_t buffer_length );
void fill_struct_from_buffer( Line *line, int number_of_lines, char *buffer );

#endif
