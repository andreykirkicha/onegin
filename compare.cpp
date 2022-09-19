#include "compare.h"

int compare( struct Line string_1, struct Line string_2 )
{
    while (!isalpha(*(string_1.str)))
        string_1.str++;

    while (!isalpha(*(string_2.str)))
        string_2.str++;

    if (*(string_1.str) == '\0' && *(string_2.str) == '\0')
        return 0;
    if (*(string_1.str) < *(string_2.str))
        return -1;
    if (*(string_1.str) > *(string_2.str))
        return 1;
    else
    {
        string_1.str++;
        string_2.str++;
    }
}
