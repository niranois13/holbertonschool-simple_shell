#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

char **parse(char *input);

// Define the extern variable environ if it's not defined
extern char **environ;

int main(void)
{
    char *input = NULL;
    size_t len = 0;
    ssize_t read;
    char **command;
    int i;

    while (1)
    {
        printf("€ ");
        read = getline(&input, &len, stdin);

        if (read == -1)
        {
            if (feof(stdin))
            {
                free(input);
                exit(EXIT_SUCCESS);
            }
            else
            {
                free(input);
                perror("getLine\n");
                exit(EXIT_FAILURE);
            }
        }

        command = parse(input);
        if (command != NULL)
        {
            // Fork a new process
            pid_t pid = fork();

            if (pid == -1)
            {
                perror("fork");
                exit(EXIT_FAILURE);
            }
            else if (pid == 0) // Child process
            {
                // Find the PATH variable in the environ array
                char *path = NULL;
                for (char **env = environ; *env != NULL; env++) {
                    if (strncmp(*env, "PATH=", 5) == 0) {
                        path = *env + 5; // Skip "PATH="
                        break;
                    }
                }

                if (path == NULL) {
                    perror("PATH");
                    exit(EXIT_FAILURE);
                }

                // Tokenize the PATH variable to get individual directories
                char *token;
                token = strtok(path, ":");
                while (token != NULL)
                {
                    // Construct the absolute path to the executable
                    char *absolute_path = malloc(strlen(token) + strlen(command[0]) + 2);
                    if (absolute_path == NULL)
                    {
                        perror("malloc");
                        exit(EXIT_FAILURE);
                    }
                    sprintf(absolute_path, "%s/%s", token, command[0]);

                    // Use execve to execute the command
                    execve(absolute_path, command, NULL);

                    // Free memory allocated for absolute path
                    free(absolute_path);

                    // Move to the next directory in PATH
                    token = strtok(NULL, ":");
                }

                // If execve fails for all directories in PATH, print an error
                perror("execve");
                exit(EXIT_FAILURE);
            }
            else // Parent process
            {
                // Wait for the child process to finish
                int status;
                waitpid(pid, &status, 0);

                // Free memory allocated for command
                for (i = 0; command[i] != NULL; i++)
                    free(command[i]);
                free(command);
            }
        }
        else
            printf("No command found.\n");
    }
    free(input);
    return 0;
}
