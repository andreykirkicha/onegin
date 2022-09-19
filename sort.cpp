#include <stdlib.h>

#include "sort.hpp"
#include "compare.hpp"
#include "input.hpp"

void bubble_sort( Line *line, int number_of_lines )
{
    for (int i = 0; i < number_of_lines - 1; i++)
        for (int j = 0; j < number_of_lines - 1; j++)
            if (compare(line[j], line[j + 1]) == 1)
                swap_lines(&line[j], &line[j + 1]);
}

void swap_lines( Line *line_1, Line *line_2 )
{
    struct Line *tmp = (Line *)calloc(1, sizeof(Line));

    tmp = line_1;
    line_1 = line_2;
    line_2 = tmp;
}
