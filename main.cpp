#include <stdio.h>
#include <stdlib.h>

#include "input.hpp"
#include "compare.hpp"
#include "sort.hpp"

int main()
{
    char file_name[] = "test.txt";
    size_t buffer_length = 0;

    char *buffer = input_to_buffer(file_name, &buffer_length);
    replace_slash_n(buffer, buffer_length);

    int number_of_lines = get_number_of_lines(buffer, buffer_length);
    Line *line = (Line *)calloc(number_of_lines, sizeof(Line));
    fill_struct_from_buffer(line, number_of_lines, buffer);
    /*
    bubble_sort(line, number_of_lines);

    for (int i = 0; i < number_of_lines; i++)
        printf("%s", line[i].str);
    */
    for (int i = 0; i < number_of_lines; i++)
        printf("%s\n", line[i].str);

    printf("%d", compare(line[0], line[1]));

    return 0;
}
