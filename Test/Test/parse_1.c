#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *parse(char *input)
{
    static char *saved_input = NULL;
    static char *current_token = NULL;

    if (input != NULL)
    {
        free(saved_input);
        saved_input = strdup(input);
        current_token = strtok(saved_input, " \t\n");
    }
    else if (current_token != NULL)
    {
        current_token = strtok(NULL, " \t\n");
    }

    return current_token;
}
