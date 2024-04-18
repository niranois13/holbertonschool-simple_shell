#include "main.h"
#define BUFFER_SIZE 1024
char *prompt_and_read_input(char **input, size_t *len)
{
    ssize_t read;
    printf("Top-Shell:€ ");
    read = getline(input, len, stdin);
    if (read == -1)
    {
        if (read == EOF)
        {
            printf("\n");
            free(*input);
            exit(EXIT_FAILURE);
        }
        else
        {
            perror("getLine\n");
            free(*input);
            exit(EXIT_FAILURE);
        }
    }
    return (*input);
}
