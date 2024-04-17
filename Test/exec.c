#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main()
{
    char str[] = "Hello World How Are You";
    char *token;

    // Get the first token
    token = strtok(str, " ");

    // Iterate through all tokens
    while (token != NULL)
	{
        printf("%s\n", token);
        // Get the next token
        token = strtok(NULL, " ");

		// Check if the file exists and is executable
		if (access("/usr/bin/executable_name", X_OK) == 0)
		{
			// If there's a match, compare the input string with the name of the executable
			if (strcmp(token, "executable_name") == 0) {
				printf("Input string matches executable_name\n");
				// Execute the command
				execve("/usr/bin/executable_name", argv, NULL);
				// If execve() returns, there was an error
				perror("execve");
				exit(EXIT_FAILURE);
			} else {
				printf("Input string does not match executable_name\n");
			}
		} else {
			printf("Executable not found\n");
		}

    }

    return 0;
}
